#include <stdio.h>
#include <stdlib.h>

void foo(int *n) {
  *n = *n + 10;
}

int main() {
  int x = 10;
  int y = 20;
  int z = 30;
  int w = 1234567;

  int* a  = new int(5);
  int* b  = new int(10);
  int* c  = new int(10);

  foo(&x);
  printf("x: %d\n", x);
  foo(a);
  printf("*a: %d\n", *a);
}
