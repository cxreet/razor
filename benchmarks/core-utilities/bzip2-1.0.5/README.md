1. Run test cases in `./train/` to collect traces:
	- `python run_razor.py train`

2. Generate the assembly files based on the collected traces:
	- `python run_razor.py debloat`

3. Run the test cases under `test`
	- `python run_razor.py test` and you would notice segmentation faults happen for some test cases.

4. Infer more code paths that are not executed for test cases under `train`
	- `python run_razor.py extend_debloat`
	- Retry step 3 and all test cases passed.
