#include "cbr_indcall.h"

/* Application module */
static app_pc exe_start;
static app_pc exe_end;
static size_t exe_size;
static char exe_name[128];

static client_id_t client_id;
static int tls_idx;

static bool SUPPORT_LIB = false;

/* Clean call for the 'taken' case */
static void at_taken(app_pc src, app_pc targ)
{
    /*
     * Record the fact that we've seen the taken case.
     */
    dr_mcontext_t mcontext = {sizeof(mcontext),DR_MC_ALL,};
    void *drcontext = dr_get_current_drcontext();
		per_thread_t *data = (per_thread_t *) drmgr_get_tls_field(drcontext, tls_idx);

		module_t *mod = NULL;
		for (unsigned i = 0; i < data->num_modules; ++i) {
			if (data->modules[i]->mod_start <= src &&
					data->modules[i]->mod_end >= src) {
				mod = data->modules[i];
				break;
			}
		}
		ASSERT(mod != NULL);

		byte *cond_table = mod->cond_table;
		cond_table[src - mod->mod_start] |= CBR_TAKEN;

    /* Remove the bb from the cache so it will be re-built the next
     * time it executes.
     */
    /* Since the flush will remove the fragment we're already in,
     * redirect execution to the target address.
     */
    dr_flush_region(src, 1);
    dr_get_mcontext(drcontext, &mcontext);
    mcontext.pc = targ;
    dr_redirect_execution(&mcontext);
}

/* Clean call for the 'not taken' case */
static void at_not_taken(app_pc src, app_pc fall)
{
    /*
     * Record the fact that we've seen the taken case.
     */
    dr_mcontext_t mcontext = {sizeof(mcontext),DR_MC_ALL,};
    void *drcontext = dr_get_current_drcontext();
		per_thread_t *data = (per_thread_t *) drmgr_get_tls_field(drcontext, tls_idx);

		module_t *mod = NULL;
		for (unsigned i = 0; i < data->num_modules; ++i) {
			if (data->modules[i]->mod_start <= src &&
					data->modules[i]->mod_end >= src) {
				mod = data->modules[i];
				break;
			}
		}
		ASSERT(mod != NULL);

		byte *cond_table = mod->cond_table;
		cond_table[src - mod->mod_start] |= CBR_NOT_TAKEN;

    /* Remove the bb from the cache so it will be re-built the next
     * time it executes.
     */
    /* Since the flush will remove the fragment we're already in,
     * redirect execution to the fallthrough address.
     */
    dr_flush_region(src, 1);
    dr_get_mcontext(drcontext, &mcontext);
    mcontext.pc = fall;
    dr_redirect_execution(&mcontext);
}



static void
at_call_ind(app_pc src, app_pc target_addr)
{
	void *drcontext = dr_get_current_drcontext();
	per_thread_t *data = (per_thread_t *) drmgr_get_tls_field(drcontext, tls_idx);

	module_t *mod = NULL;
	for (unsigned i = 0; i < data->num_modules; ++i) {
		if (data->modules[i]->mod_start <= src &&
				data->modules[i]->mod_end >= src) {
			mod = data->modules[i];
			break;
		}
	}
	ASSERT(mod != NULL);

	hash_table_t indcall_table = mod->indcall_table;
	
	uint index = hash_func(src);
	list_t *list = indcall_table[index];
	if (list == NULL) {
		list = new_list();
		indcall_table[index] = list;
	}

	elem_t *elem = find_elem(list, src, target_addr);
	if (elem == NULL) {
		elem_t *elem = (elem_t *)dr_thread_alloc(drcontext, sizeof(elem_t));
		ASSERT(elem != NULL);

		elem->next = NULL;
		elem->addr = src;
		elem->tgt_addr = target_addr;
		elem->hit = 1;

		append_elem(list, elem);
	} else {
		elem->hit += 1;
	}
}

static dr_emit_flags_t
event_app_instruction(void *drcontext, void *tag, instrlist_t *bb, instr_t *instr,
		bool for_trace, bool translating, void *user_data)
{

	/* Only trace in app BBs */
	if (!SUPPORT_LIB) { 
		module_data_t *tmp_mod = dr_lookup_module(dr_fragment_app_pc(tag));
		if (tmp_mod != NULL) {
			bool from_exe = (tmp_mod->start == exe_start);
			dr_free_module_data(tmp_mod);
			if (!from_exe) {
				return DR_EMIT_DEFAULT;
			}
		}
	}

	/* get the block start and end addresses */
	instr_t *first_instr = instrlist_first_app(bb);
	instr_t *last_instr = instrlist_last_app(bb);
	app_pc curr_pc = instr_get_app_pc(instr);
	app_pc start_bb_addr = instr_get_app_pc(first_instr);
	app_pc end_bb_addr = instr_get_app_pc(last_instr) + instr_length(drcontext, last_instr) - 1;

	per_thread_t *data = (per_thread_t *) drmgr_get_tls_field(drcontext, tls_idx);
	module_t *mod = NULL;
	for (unsigned i = 0; i < data->num_modules; ++i) {
		if (data->modules[i]->mod_start <= curr_pc &&
				data->modules[i]->mod_end >= curr_pc) {
			mod = data->modules[i];
			break;
		}
	}
	// if the current module is not found
	if (mod == NULL) {
		mod = (module_t *) dr_thread_alloc(drcontext, sizeof(module_t));
		mod->mod_name = (char*) dr_thread_alloc(drcontext, sizeof(char) * 128);

		module_data_t *exe_mod = dr_lookup_module(dr_fragment_app_pc(tag));
		ASSERT(exe_mod != NULL);
		strncpy(mod->mod_name, exe_mod->full_path, 128);
		mod->mod_start = exe_mod->start;
		
		//TODO: assume there is only one EXEC segment
		for (unsigned i = 0; i < exe_mod->num_segments; ++i) {
			module_segment_data_t	seg = exe_mod->segments[i];
			if (seg.prot & DR_MEMPROT_EXEC) {
				mod->mod_end = seg.end;
			}
		}

		ASSERT(mod->mod_end > 0);
		mod->mod_size = mod->mod_end - mod->mod_start;

		mod->cond_table = dr_thread_alloc(drcontext, mod->mod_size);
		for (unsigned i = 0; i < mod->mod_size; ++i) {
			mod->cond_table[i] = CBR_NEITHER;
		}

		mod->indcall_table = new_table();

		mod->executed_bbs = dr_thread_alloc(drcontext, mod->mod_size);
		for (unsigned i = 0; i < mod->mod_size; ++i) {
			mod->executed_bbs[i] = 0;
		}

		data->modules[data->num_modules] = mod;
		data->num_modules += 1;
		dr_free_module_data(exe_mod);
	}
	
	/* get the executed bb table and contional bb table */
	byte *executed_bbs = mod->executed_bbs;
	byte *cond_table = mod->cond_table;
	// mark the executed instructions
	unsigned start_offset = start_bb_addr - mod->mod_start;
	unsigned end_offset = end_bb_addr - mod->mod_start;
	executed_bbs[start_offset] |= 1;
	executed_bbs[end_offset] |= 2;
	//fprintf(data->log, "%p %p\n", start_bb_addr, end_bb_addr);
	/*
	for (unsigned i = start_offset; i <= end_offset; ++i) {
		executed_bbs[i] = 1;
	}
	*/

	/* conditional branch and indirect call/jump only */
	if (!instr_is_cbr(instr) && 
			!instr_is_mbr(instr))
		return DR_EMIT_DEFAULT;

	/* currently, don't instrument return */
	if (instr_is_return(instr)) {
		return DR_EMIT_DEFAULT;
	}

	/* indirect call */
	if (instr_is_mbr(instr)) {
		dr_insert_mbr_instrumentation(drcontext, bb, instr, (app_pc) at_call_ind,
				SPILL_SLOT_1);
		return DR_EMIT_DEFAULT;
	}

#ifdef NO_CND_TRACING	
	return DR_EMIT_DEFAULT;
#endif

	/* conditional branch */
	if (instr_is_cbr(instr)) {
		bool insert_taken = false;
		bool insert_not_taken = false;

		insert_taken = (cond_table[curr_pc - mod->mod_start] & CBR_TAKEN) == 0;
		insert_not_taken = (cond_table[curr_pc - mod->mod_start] & CBR_NOT_TAKEN) == 0;

		if (insert_taken || insert_not_taken) {
			app_pc fall = (app_pc) decode_next_pc(drcontext, (byte *) curr_pc);
			app_pc targ = instr_get_branch_target_pc(instr);
      
			instr_t *label = INSTR_CREATE_label(drcontext);
      instr_set_meta_no_translation(instr);
      if (instr_is_cti_short(instr)) {
      	instr = instr_convert_short_meta_jmp_to_long(drcontext, bb, instr);
      }
      instr_set_target(instr, opnd_create_instr(label));

      if (insert_not_taken) {
      	dr_insert_clean_call(drcontext, bb, NULL,
                             (void*)at_not_taken,
                              false /* don't save fp state */,
                              2 /* 2 args for at_not_taken */,
                              OPND_CREATE_INTPTR(curr_pc),
                              OPND_CREATE_INTPTR(fall));
      }

      instrlist_preinsert(bb, NULL,
                          INSTR_XL8(INSTR_CREATE_jmp
                          (drcontext, opnd_create_pc(fall)), fall));
      MINSERT(bb, NULL, label);

      if (insert_taken) {
      	dr_insert_clean_call(drcontext, bb, NULL,
                             (void*)at_taken,
                             false /* don't save fp state */,
                             2 /* 2 args for at_taken */,
                             OPND_CREATE_INTPTR(curr_pc),
                             OPND_CREATE_INTPTR(targ));
      }

      instrlist_preinsert(bb, NULL,
                          INSTR_XL8(INSTR_CREATE_jmp
                          (drcontext, opnd_create_pc(targ)), targ));


		}
	}

  return DR_EMIT_STORE_TRANSLATIONS;
}


static void
event_thread_init(void *drcontext)
{
	per_thread_t *data;

	/* allocate thread private data */
	data = (per_thread_t *) dr_thread_alloc(drcontext, sizeof(per_thread_t));
	drmgr_set_tls_field(drcontext, tls_idx, data);
	
	/* initialize the data */
	data->num_modules = 1;
	data->modules = (module_t **) dr_thread_alloc(drcontext, sizeof(module_t*) * 128);
	data->modules[0] = (module_t *) dr_thread_alloc(drcontext, sizeof(module_t));
	// the main module
	data->modules[0]->mod_name = (char*) dr_thread_alloc(drcontext, sizeof(char) * 128);
	strncpy(data->modules[0]->mod_name, exe_name, 128);
	data->modules[0]->mod_start = exe_start;
	data->modules[0]->mod_end = exe_end;
	data->modules[0]->mod_size = exe_size;

	data->modules[0]->cond_table = dr_thread_alloc(drcontext, exe_size);
	for (unsigned i = 0; i < exe_size; ++i) {
		data->modules[0]->cond_table[i] = CBR_NEITHER;
	}

	data->modules[0]->indcall_table = new_table();

	data->modules[0]->executed_bbs = dr_thread_alloc(drcontext, exe_size);
	for (unsigned i = 0; i < exe_size; ++i) {
		data->modules[0]->executed_bbs[i] = 0;
	}

  file_t log_fd = log_file_open(client_id, drcontext, NULL, "cbr_indcall", 
													  DR_FILE_CLOSE_ON_FORK | DR_FILE_ALLOW_LARGE);
	data->log = log_stream_from_file(log_fd);
	data->file_is_open = true;
}

static void dump_file(void *drcontext) {
	per_thread_t *data = (per_thread_t *) drmgr_get_tls_field(drcontext, tls_idx);
	if (!data->file_is_open)
		return;

#ifdef SHOW_RESULTS
	for (unsigned i = 0; i < data->num_modules; i++) {
		module_t *mod = data->modules[i];
		byte *cond_table = mod->cond_table;
		hash_table_t indcall_table = mod->indcall_table;
		byte *executed_bbs = mod->executed_bbs;
		app_pc mod_start = mod->mod_start;
		app_pc mod_end = mod->mod_end;
		size_t mod_size = mod->mod_size;
		

		fprintf(data->log, "MODULE_NAME: %s\n", mod->mod_name);
		fprintf(data->log, "MODULE_START: %p\n", mod_start);
		
		// Print all executed instruction address
		// 
		app_pc bb_start = 0;
		app_pc bb_end = 0;
		for (unsigned i = 0; i < mod_size; ++i) {
			if (executed_bbs[i] == 1) {
				if (bb_start != 0) {
					fprintf(data->log, "+B+: %p %p\n", bb_start, mod_start + i - 1);
				}
				bb_start = mod_start + i;
			} else if (executed_bbs[i] == 2) {
				ASSERT(bb_start != 0);
				bb_end = i + mod_start;
				fprintf(data->log, "+B+: %p %p\n", bb_start, bb_end);
				bb_start = 0;
				//bb_end = 0;
			} else if (executed_bbs[i] == 3) {
				bb_end = i + mod_start;
				if (bb_start != 0) {
					fprintf(data->log, "+B+: %p %p\n", bb_start, bb_end);
					
					unsigned next_flag = 0;	
					for (unsigned j= i + 1; j < mod_size; ++j) {
						if (executed_bbs[j] != 0) {
							next_flag = executed_bbs[j];
							break;
						}
					}

					if (next_flag == 1) {
						bb_start = 0;
					} else if (next_flag == 2) {
						bb_start = bb_end;
					} else if (next_flag == 0) {
						bb_end = 0;
					} else if (next_flag == 3) {
						bb_end = 0;
					}
				} else {
					fprintf(data->log, "+B+: %p %p\n", bb_end, bb_end);
					bb_start = 0;
					//bb_end = 0;
				}
			}
		}

		/*
			 unsigned cur_start = 0;
		for (unsigned i = 0; i < mod_size; ++i) {
			if (executed_bbs[i] == 1) {
				if (cur_start == 0) {
					cur_start = i;
				}
			} else {
				if (cur_start != 0) {
					fprintf(data->log, "B: %p %p\n", mod_start + cur_start, mod_start + i - 1);
					cur_start = 0;
				}
			}
		}
		*/

		// Print all the cbr's seen over the life of the process, and
		// whether we saw taken, not taken, or both.
		//
		for (unsigned i = 0; i < mod_size; ++i) {
			if (cond_table[i] == CBR_TAKEN) {
				fprintf(data->log, "+CND+ %p: taken\n", mod_start + i);
			} else if (cond_table[i] == CBR_NOT_TAKEN) {
				fprintf(data->log, "+CND+ %p: not taken\n", mod_start + i);
			} else if (cond_table[i] == (CBR_TAKEN | CBR_NOT_TAKEN)) {
				fprintf(data->log, "+CND+ %p: both\n", mod_start + i);
			}
		}

		// Print all indirect call's src addr and targets
		//
		for (unsigned i = 0; i < HASH_TABLE_SIZE; i++) {
			if (indcall_table[i] != NULL) {
				elem_t *iter;
				for (iter = indcall_table[i]->head; iter != NULL; iter = iter->next) {
					fprintf(data->log, "@%p to %p %u\n", iter->addr, iter->tgt_addr, iter->hit);
				}
			}
		}

		dr_thread_free(drcontext, cond_table, mod_size);
		delete_table(indcall_table);
		dr_thread_free(drcontext, executed_bbs, mod_size);
	}
#endif
	
	log_stream_close(data->log);
	data->file_is_open = false;
}

static void
event_thread_exit(void *drcontext)
{
	dump_file(drcontext);
}

void
dr_exit(void)
{
	if (!drmgr_unregister_tls_field(tls_idx) ||
			!drmgr_unregister_thread_init_event(event_thread_init) ||
			!drmgr_unregister_thread_exit_event(event_thread_exit))
		DR_ASSERT(false);

	drmgr_exit();
}

static bool
event_filter_syscall(void *drcontext, int sysnum)
{
		if (sysnum == SYS_execve)
    	return true; /* intercept execve */
		return false;
}

static bool
event_pre_syscall(void *drcontext, int sysnum)
{
	if (sysnum == SYS_execve) {
		per_thread_t *data = (per_thread_t *) drmgr_get_tls_field(drcontext, tls_idx);
		if (data->file_is_open) {
			thread_id_t tid = dr_get_thread_id(drcontext);
			dr_printf("%d execve %d\n", tid, sysnum);
			dump_file(drcontext);
		}
	}
	return true;
}

DR_EXPORT
void
dr_client_main(client_id_t id, int argc, const char *argv[])
{

	if (argc >= 2) {
		if (strcmp(argv[1], "--lib") == 0)
			SUPPORT_LIB = true;
	}

	dr_set_client_name("DynamoRIO Sample Client 'cbr'", "http://dynamorio.org/issues");

	if (!drmgr_init())
		DR_ASSERT_MSG(false, "drmgr_init failed!");
	
	/* hook execve system call */
  dr_register_filter_syscall_event(event_filter_syscall);
  drmgr_register_pre_syscall_event(event_pre_syscall);


	/* Get main module address */
	module_data_t *exe = dr_get_main_module();
	if (exe != NULL) {
		strncpy(exe_name, exe->full_path, 128);
		exe_start = exe->start;

		for (unsigned i = 0; i < exe->num_segments; ++i) {
			module_segment_data_t	seg = exe->segments[i];
			if (seg.prot & DR_MEMPROT_EXEC) {
				exe_end = seg.end;
			}
		}

		exe_size = exe_end - exe_start;
		if (exe_size > 0x1000000) {
			dr_printf("WARN: exe_size is too huge\n");
			exe_size = 0x1000000;
		}
		//dr_printf("exe_start: %p exe_end: %p\n", exe_start, exe_end);
	}
	dr_free_module_data(exe);


	client_id = id;
	tls_idx = drmgr_register_tls_field();

	if (!drmgr_register_thread_init_event(event_thread_init) ||
			!drmgr_register_thread_exit_event(event_thread_exit) ||
			!drmgr_register_bb_instrumentation_event(NULL, event_app_instruction, NULL))
		DR_ASSERT_MSG(false, "fail to register event_app_instruction!");
	dr_register_exit_event(dr_exit);
}
