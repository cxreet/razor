1. Run test cases in `./train/` to collect traces:
	- `python run_razor.py train`

2. Generate the assembly files based on the collected traces:
	- `python run_razor.py debloat`

3. Manually fixed the values for entry point:
	- Open `bzip2.s` and start from `L_0x400f50:`
	- Replace the three arguments: 
		- `mov r8, 0x419540` to `mov r8, offset L_0x419540`
		- `mov rcx, 0x4194d0` to `mov rcx, offset L_0x4194d0`
		- `mov rdi, 0x410820` to `mov rdi, offset L_0x410820`

4. Regenerate the debloated binary:
	- `python run_razor.py debloat_patch`	

5. Run the test cases under `test`
	- `python run_razor.py test` and you would notice segmentation faults happen for some test cases.

6. Infer more code paths that are not executed for test cases under `train`
	- `python run_razor.py extend_debloat`

7. Retry step 3 to step 5 and you would notice no segmentation faults happen for all test cases.
