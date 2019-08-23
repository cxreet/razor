#include "dr_api.h"
#include "drmgr.h"
#include "utils.h"
#include <syscall.h>
#include <string.h>

#define MINSERT instrlist_meta_preinsert
#define SHOW_RESULTS
//#define NO_CND_TRACING

#define ASSERT(x)                                            \
	do {                                                     \
		if (!(x)) {                                          \
			dr_printf("ASSERT failed on line %d", __LINE__); \
			dr_flush_file(STDOUT);                           \
			dr_abort();                                      \
		}                                                    \
	} while (0)

/* We need a table to store the state of each cbr (i.e., "seen taken
 * edge", "seen fallthrough edge", or "seen both").  We'll use a
 * simple hash table.
 */
#define HASH_TABLE_SIZE 7919

typedef unsigned char byte;

/* Possible cbr states */
typedef enum { CBR_NEITHER = 0, CBR_TAKEN = 1, CBR_NOT_TAKEN = 2 } cbr_state_t;

typedef struct _elem_t {
	struct _elem_t *next;
	app_pc addr;
	app_pc tgt_addr;
	unsigned hit;
} elem_t;

typedef struct _list_t {
	elem_t *head;
	elem_t *tail;
} list_t;

typedef list_t **hash_table_t;

static bool event_filter_syscall(void *drcontext, int sysnum);
static bool event_pre_syscall(void *drcontext, int sysnum);
static void dump_file(void *drcontext);

static elem_t *
new_elem(app_pc addr)
{
	void *drcontext = dr_get_current_drcontext();
	elem_t *elem = (elem_t *)dr_thread_alloc(drcontext, sizeof(elem_t));
	ASSERT(elem != NULL);

	elem->next = NULL;
	elem->hit = 0;
	return elem;
}

static void
delete_elem(elem_t *elem)
{
	void *drcontext = dr_get_current_drcontext();
	dr_thread_free(drcontext, elem, sizeof(elem_t));
}

static void
append_elem(list_t *list, elem_t *elem)
{
	if (list->head == NULL) {
		ASSERT(list->tail == NULL);
		list->head = elem;
		list->tail = elem;
	} else {
		list->tail->next = elem;
		list->tail = elem;
	}
}

static elem_t *
find_elem(list_t *list, app_pc addr, app_pc ind_tgt_addr)
{
	elem_t *elem = list->head;
	while (elem != NULL) {
		/* indirect call */
		if (elem->addr == addr && elem->tgt_addr == ind_tgt_addr) {
			return elem;
		}
		elem = elem->next;
	}

	return NULL;
}

static list_t *
new_list()
{
	void *drcontext = dr_get_current_drcontext();
	list_t *list = (list_t *)dr_thread_alloc(drcontext, sizeof(list_t));
	list->head = NULL;
	list->tail = NULL;
	return list;
}

static void
delete_list(list_t *list)
{
	elem_t *iter = list->head;
	while (iter != NULL) {
		elem_t *next = iter->next;
		delete_elem(iter);
		iter = next;
	}

	void *drcontext = dr_get_current_drcontext();
	dr_thread_free(drcontext, list, sizeof(list_t));
}

hash_table_t
new_table()
{
	void *drcontext = dr_get_current_drcontext();
	int i;
	hash_table_t table =
		(hash_table_t)dr_thread_alloc(drcontext, sizeof(list_t *) * HASH_TABLE_SIZE);

	for (i = 0; i < HASH_TABLE_SIZE; i++) {
		table[i] = NULL;
	}

	return table;
}

void
delete_table(hash_table_t table)
{
	int i;
	for (i = 0; i < HASH_TABLE_SIZE; i++) {
		if (table[i] != NULL) {
			delete_list(table[i]);
		}
	}

	void *drcontext = dr_get_current_drcontext();
	dr_thread_free(drcontext, table, sizeof(list_t *) * HASH_TABLE_SIZE);
}

static uint
hash_func(app_pc addr)
{
	return ((uint)(((ptr_uint_t)addr) % HASH_TABLE_SIZE));
}

elem_t *
lookup(hash_table_t table, app_pc addr)
{
	list_t *list = table[hash_func(addr)];
	if (list != NULL)
		return find_elem(list, addr, 0);

	return NULL;
}

void
insert(hash_table_t table, app_pc addr)
{
	elem_t *elem = new_elem(addr);

	uint index = hash_func(addr);
	list_t *list = table[index];
	if (list == NULL) {
		list = new_list();
		table[index] = list;
	}

	append_elem(list, elem);
}

/*
 * End hash table implementation
 */
typedef struct _module_t {
	char *mod_name;
	app_pc mod_start;
	app_pc mod_end;	
	size_t mod_size;
	/* For conditional branch */
	byte* cond_table;
	/* For indirect call and return */
	hash_table_t indcall_table;
	/* The executed block list */
	byte* executed_bbs;
} module_t;

typedef struct _per_thread_t {
	size_t num_modules;
	module_t **modules;
	FILE *log;
	bool file_is_open;
} per_thread_t;
