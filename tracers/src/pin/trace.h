#ifndef __PIN_TRACE__
#define __PIN_TRACE__

#include <iostream>
#include <fstream>
#include "pin.H"

KNOB<string> KnobOutputFile(KNOB_MODE_WRITEONCE, "pintool",
		"o", "", "specify output file name");


// Force each thread's data to be in its own data cache line so that
// multiple threads do not contend for the same data cache line.
// This avoids the false sharing problem.
#define PADSIZE 56  // 64 byte line size: 64-8

#define HASH_TABLE_SIZE 7919

typedef unsigned char byte;

// key for accessing TLS storage in the threads. initialized once in main()
static  TLS_KEY tls_key = INVALID_TLS_KEY;

// Main executable address region
static ADDRINT exe_start = 0;
static ADDRINT exe_end = 0;
static UINT32 exe_size = 0;
static ADDRINT MODULE_START = 0;
static const char * MODULE_NAME;

typedef struct _elem_t {
	struct _elem_t *next;
	ADDRINT addr;
	ADDRINT tgt_addr;
	unsigned hit;
} elem_t;

typedef struct _list_t {
	elem_t *head;
	elem_t *tail;
} list_t;

typedef list_t **hash_table_t;

static elem_t *
new_elem(ADDRINT addr)
{
	elem_t *elem = (elem_t *)malloc(sizeof(elem_t));

	elem->next = NULL;
	elem->hit = 0;
	return elem;
}

static void
delete_elem(elem_t *elem)
{
	free(elem);
}

static void
append_elem(list_t *list, elem_t *elem)
{
	if (list->head == NULL) {
		list->head = elem;
		list->tail = elem;
	} else {
		list->tail->next = elem;
		list->tail = elem;
	}
}

static elem_t *
find_elem(list_t *list, ADDRINT addr, ADDRINT ind_tgt_addr)
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
	list_t *list = (list_t*) malloc(sizeof(list_t));
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

	free(list);
}

hash_table_t
new_table()
{
	int i;
	hash_table_t table =
		(hash_table_t)malloc(sizeof(list_t *) * HASH_TABLE_SIZE);

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

	free(table);
}

static UINT32
hash_func(ADDRINT addr)
{
	return ((UINT32)(addr % HASH_TABLE_SIZE));
}

elem_t *
lookup(hash_table_t table, ADDRINT addr)
{
	list_t *list = table[hash_func(addr)];
	if (list != NULL)
		return find_elem(list, addr, 0);

	return NULL;
}

void
insert(hash_table_t table, ADDRINT addr)
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

// a running count of the instructions
class thread_data_t
{
	public:
		thread_data_t() : _executed_bbs(NULL), _cond_table(NULL),
 											_indcall_table(NULL)	{}
		byte* _executed_bbs;
		byte* _cond_table;
		hash_table_t _indcall_table;
		UINT8 _pad[PADSIZE];
};

#endif
