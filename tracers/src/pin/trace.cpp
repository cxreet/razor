/*BEGIN_LEGAL 
Intel Open Source License 

Copyright (c) 2002-2018 Intel Corporation. All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */

#include "trace.h"

VOID ThreadStart(THREADID threadid, CONTEXT *ctxt, INT32 flags, VOID *v)
{
	thread_data_t* tdata = new thread_data_t;

	tdata->_executed_bbs = (byte*) calloc(exe_size, sizeof(byte));
	tdata->_cond_table = (byte*) calloc(exe_size, sizeof(byte));
	tdata->_indcall_table = new_table();

	if (PIN_SetThreadData(tls_key, tdata, threadid) == FALSE)
	{
		cerr << "PIN_SetThreadData failed" << endl;
		PIN_ExitProcess(1);
	}
}


// This function is called before every block
VOID PIN_FAST_ANALYSIS_CALL RunBB(ADDRINT start_addr, ADDRINT end_addr, THREADID threadid)
{
	//cerr << hexstr(start_addr) << '-' << hexstr(end_addr) << ' ' << threadid << '\n';
	thread_data_t* tdata = static_cast<thread_data_t*>(PIN_GetThreadData(tls_key, threadid));
	byte* executed_bbs = tdata->_executed_bbs;

	UINT32 start_offset = start_addr - exe_start;
	UINT32 end_offset = end_addr - exe_start;
	executed_bbs[start_offset] |= 1;
	executed_bbs[end_offset] |= 2;
}

VOID PIN_FAST_ANALYSIS_CALL RunCndBr(ADDRINT addr, BOOL taken, THREADID threadid) {
	thread_data_t* tdata = static_cast<thread_data_t*>(PIN_GetThreadData(tls_key, threadid));
	byte* cond_table = tdata->_cond_table;

	UINT32 offset = addr - exe_start;
	if (taken) {
		cond_table[offset] |= 1;
	} else {
		cond_table[offset] |= 2;
	}
}

VOID PIN_FAST_ANALYSIS_CALL RunIndCall(ADDRINT addr, ADDRINT tgt, THREADID threadid) {
	//cerr << hexstr(addr) << " --> " << hexstr(tgt) << '\n';
	thread_data_t* tdata = static_cast<thread_data_t*>(PIN_GetThreadData(tls_key, threadid));
	hash_table_t indcall_table = tdata->_indcall_table;

	UINT32 index = hash_func(addr);
	list_t *list = indcall_table[index];
	if (list == NULL) {
		list = new_list();
		indcall_table[index] = list;
	}

	elem_t *elem = find_elem(list, addr, tgt);
	if (elem == NULL) {
		elem_t *elem = (elem_t *)malloc(sizeof(elem_t));

		elem->next = NULL;
		elem->addr = addr;
		elem->tgt_addr = tgt;
		elem->hit = 1;

		append_elem(list, elem);
	} else {
		elem->hit += 1;
	}
}

// Pin calls this function every time a new basic block is encountered.
// It inserts a call to RunBB.
VOID Trace(TRACE trace, VOID *v)
{
	// Visit every basic block  in the trace
	for (BBL bbl = TRACE_BblHead(trace); BBL_Valid(bbl); bbl = BBL_Next(bbl))
	{

		ADDRINT start_addr = BBL_Address(bbl);
		INS tail = BBL_InsTail(bbl);	
		ADDRINT end_addr = INS_Address(tail) + INS_Size(tail) - 1;

		if (start_addr >= exe_start && start_addr <= exe_end) 
		{
			//cerr << hexstr(start_addr) << '-' << hexstr(end_addr) << ' ' << INS_IsDirectBranchOrCall(tail) << ' ' << INS_IsIndirectBranchOrCall(tail) << '\n';
			BBL_InsertCall(bbl, IPOINT_BEFORE, (AFUNPTR)RunBB, IARG_FAST_ANALYSIS_CALL,
					IARG_ADDRINT, start_addr, IARG_ADDRINT, end_addr, IARG_THREAD_ID, IARG_END);

			if (INS_Category(tail) == XED_CATEGORY_COND_BR && !INS_IsXend(tail)) {
				INS_InsertCall(tail, IPOINT_BEFORE, AFUNPTR(RunCndBr), IARG_FAST_ANALYSIS_CALL,
						IARG_ADDRINT, INS_Address(tail), IARG_BRANCH_TAKEN, IARG_THREAD_ID, IARG_END);
			}

			if (INS_IsIndirectBranchOrCall(tail) && !INS_IsRet(tail)) {
      	//cerr << "Instrumenting at " << hex << INS_Address(tail) << " " << INS_Disassemble(tail).c_str() << std::endl;
				INS_InsertCall(tail, IPOINT_BEFORE, AFUNPTR(RunIndCall), IARG_FAST_ANALYSIS_CALL,
						IARG_ADDRINT, INS_Address(tail), IARG_BRANCH_TARGET_ADDR, IARG_THREAD_ID, IARG_END);
			}

		}
	}
}

static VOID ImageLoad(IMG img, VOID * v)
{
	if (IMG_IsMainExecutable(img)) {
		//MODULE_START = IMG_StartAddress(img);  // cannot get the correct address
		MODULE_START = IMG_LowAddress(img);
		//MODULE_NAME = IMG_Name(img).c_str();
		MODULE_NAME = "main";
		for (SEC sec = IMG_SecHead(img); SEC_Valid(sec); sec = SEC_Next(sec)) {
			if (SEC_IsExecutable(sec)) {
				if (exe_start == 0) {
					exe_start = SEC_Address(sec);
				}
				//cerr << SEC_Name(sec) << '\n';
				//cerr << hexstr(SEC_Address(sec)) << " : " << hexstr(SEC_Size(sec)) << '\n';
				exe_end = SEC_Address(sec) + SEC_Size(sec);
			}
		}
		exe_size = exe_end - exe_start;
		cerr << "exe: " << hexstr(exe_start) << " " << hexstr(exe_end) << '\n';
	}
}

// This function is called when the thread exits
VOID ThreadFini(THREADID threadIndex, const CONTEXT *ctxt, INT32 code, VOID *v)
{
	thread_data_t* tdata = static_cast<thread_data_t*>(PIN_GetThreadData(tls_key, threadIndex));
	byte* executed_bbs = tdata->_executed_bbs;
	byte* cond_table = tdata->_cond_table;
	hash_table_t indcall_table = tdata->_indcall_table;

	ostream* outFile = KnobOutputFile.Value().empty() ? new std::ofstream(decstr(threadIndex).c_str()) 
		: new std::ofstream((KnobOutputFile.Value() + "-" + decstr(threadIndex)).c_str());
	
	*outFile << "MODULE_NAME: " << MODULE_NAME << "\n";
	*outFile << "MODULE_START: 0x" << std::hex << MODULE_START << '\n';	
	// dump executed bbs
	ADDRINT bb_start = 0;
	ADDRINT bb_end = 0;
	for (UINT32 i = 0; i < exe_size; ++i) {
		if (executed_bbs[i] == 1) {
			if (bb_start != 0) {
				*outFile << "+B+: 0x" << std::hex << bb_start << " 0x" << (exe_start + i - 1) << '\n';
			}
			bb_start = exe_start + i;
		} else if (executed_bbs[i] == 2) {
			bb_end = i + exe_start;
			*outFile << "+B+: 0x" << std::hex << bb_start <<  " 0x" << bb_end << '\n';
			bb_start = 0;
			bb_end = 0;
		} else if (executed_bbs[i] == 3) {
			bb_end = i + exe_start;
			if (bb_start != 0) {
				*outFile << "+B+: 0x" << std::hex << bb_start << " 0x" << bb_end << '\n';
			} else {
				*outFile << "+B+: 0x" << std::hex << bb_end << " 0x" << bb_end << '\n';
			}
			bb_start = 0;
			bb_end = 0;
		}
	}
	
	// dump conditional branches
	for (UINT32 i = 0; i < exe_size; ++i) {
		if (cond_table[i] == 0x1) {
			*outFile << "+CND+ 0x" << std::hex << (exe_start + i) << ": taken\n";
		} else if (cond_table[i] == 0x2) {
			*outFile << "+CND+ 0x" << std::hex << (exe_start + i) << ": not taken\n";
		} else if (cond_table[i] == 0x3) {
			*outFile << "+CND+ 0x" << std::hex << (exe_start + i) << ": both\n";
		}
	}
	
	// dump indirect calls
	for (UINT32 i = 0; i < HASH_TABLE_SIZE; i++) {
		if (indcall_table[i] != NULL) {
			elem_t *iter;
			for (iter = indcall_table[i]->head; iter != NULL; iter = iter->next) {
				*outFile << "@0x" << std::hex << iter->addr << " to 0x" << iter->tgt_addr << " " << std::dec << iter->hit << "\n";
			}
		}
	}

	outFile->flush();
	free(tdata->_executed_bbs);
	delete tdata;
}

// This function is called when the application exits
VOID Fini(INT32 code, VOID *v)
{
}

/* ===================================================================== */
/* Print Help Message                                                    */
/* ===================================================================== */

INT32 Usage()
{
	cerr << "This tool counts the number of dynamic instructions executed" << endl;
	cerr << endl << KNOB_BASE::StringKnobSummary() << endl;
	return 1;
}

/* ===================================================================== */
/* Main                                                                  */
/* ===================================================================== */

int main(int argc, char * argv[])
{
	// Initialize pin
	PIN_InitSymbols();
	if (PIN_Init(argc, argv))
		return Usage();

	// Obtain  a key for TLS storage.
	tls_key = PIN_CreateThreadDataKey(NULL);
	if (tls_key == INVALID_TLS_KEY)
	{
		cerr << "number of already allocated keys reached the MAX_CLIENT_TLS_KEYS limit" << endl;
		PIN_ExitProcess(1);
	}

	// Register ThreadStart to be called when a thread starts.
	PIN_AddThreadStartFunction(ThreadStart, NULL);

	// Register Fini to be called when thread exits.
	PIN_AddThreadFiniFunction(ThreadFini, NULL);

	// Register Fini to be called when the application exits.
	PIN_AddFiniFunction(Fini, NULL);

	// Register Trace to be called to instrument instructions.
	TRACE_AddInstrumentFunction(Trace, NULL);

	// Register ImageLoad to be called when loading images.
	IMG_AddInstrumentFunction(ImageLoad, 0);

	// Start the program, never returns
	PIN_StartProgram();

	return 1;
}
