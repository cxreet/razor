#include <stdio.h>
#include <stdlib.h>

void test_heuristic_one(int a, int b) {
	printf("Testing heuristic one...\n");
	if (a > b) {
		printf("%d > %d\n", a , b);
	}
	printf("Done.\n");
	
	return;
}

int test_heuristic_two(int a, int b) {
	printf("Testing heuristic two...\n");
	int ret = 0;
	if (a > b) {
		printf("%d > %d\n", a, b);
		ret = a - b;
	} else {
		ret = b - a;	
	}
	printf("Done.\n");
	return ret;
}

void test_heuristic_three(int a, int b) {
	printf("Testing herusitc three...\n");
	if (a > b) {
		printf("%d > %d\n", a, b);
	} else {
		printf("%d <= %d\n", a, b);
	}
	printf("Done.\n");
}

void call_new_libcalls(int a, int b) {
		putw(a, stdout);
		printf(" <= ");
		putw(b, stdout);
		printf("\n");
}

void test_heuristic_four(int a, int b) {
	printf("Testing heuristic four...\n");
	if (a > b) {
		printf("%d > %d\n", a, b);
	} else {
		call_new_libcalls(a, b);
	}
	printf("Done.\n");
}

int main(int argc, char * argv[]) {
	if (argc != 3) {
		printf("Usage: ./simple n1 n2\n"); 
		return -1;
	}

	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	test_heuristic_one(a, b);
	test_heuristic_two(a, b);
	test_heuristic_three(a, b);
	test_heuristic_four(a, b);

  return 0;
}
