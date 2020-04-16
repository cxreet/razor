#include <stdio.h>
#include <stdlib.h>

typedef void (*Ftype)();

void printYes() { printf("Yes\n"); }
void printNo() { printf("No\n"); }


int main(int argc, char * argv[]) {

  if (argc != 3) {
    printf("Usage: ./simple [0|1] [y|n]\n"); return -1;
  }

  int taken = atoi(argv[1]);
  char target = argv[2][0];

  if (taken == 1)
    printf("Taken\n");
  else
    printf("Non-taken\n");

  Ftype fptr = NULL;
  if (target == 'y')
    fptr = &printYes;
  else
    fptr = &printNo;

  (*fptr)();

  return 0;
}
