1. Run test cases in `./train/` to collect traces:
	- `python run_razor.py train`

2. Generate the assembly files based on the collected traces:
	- `python run_razor.py debloat`

3. Regenerate the debloated binary:
	- `python run_razor.py debloat_patch`	

4. Run the test cases under `test`
	- `python run_razor.py test` and you would notice segmentation faults happen for some test cases.

5. Infer more code paths that are not executed for test cases under `train`
	- `python run_razor.py extend_debloat`

6. Retry step 3 to step 5 and you would notice no segmentation faults happen for all test cases.
