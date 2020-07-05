#include <stdio.h>
#include <stdlib.h>

typedef void (*Ftype)();

void printYes() { printf("Yes\n"); }
void printNo() { printf("No\n"); }

void test_heuristic_one(int a, int b) {
	if (a > b) {
		printf("a > b\n");
	}
	printf("Test heuristic one.\n");
	
	return;
}

int test_heuristic_two(int a, int b) {
	int ret = 0;
	if (a > b) {
		printf("a > b\n");
		ret = a - b;
	} else {
		ret = b - a;	
	}
	printf("Test heuristic two.\n");
	return ret;
}

void test_heuristic_three(int a, int b) {
	if (a > b) {
		printf("a > b\n");
	} else {
		printf("a <= b\n");
	}
	printf("Test heuristic three.\n");
}

void test_heuristic_four(int a, int b) {
	if (a > b) {
		printf("a > b\n");
	} else {
		fprintf(stdout, "a <= b\n");
	}
	printf("Test heuristic four.\n");
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
