Under each benchmark directory:
1. Run training cases to collect traces:
	- `python run_razor.py train`

2. Debloat the binary using the traces:
	- `python run_razor.py debloat`

3. Run the testing cases:
	- `python run_razor.py test` and you would notice segmentation faults happen for some test cases.

4. Infer more code paths that are not executed for training cases:
	- `python run_razor.py extend_debloat`
	- Retry step 3.