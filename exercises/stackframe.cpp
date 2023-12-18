#include <iostream>
#include <string>

using namespace std;

int bar(int a) {
  int x = 2*a;
  return x;
}

int foo(int a, int b) {
  int x;
  int y;
  x = a;
  y = bar(b);
  return x+y;
}

int main() {
  int a=5;
  foo(2,3);
}
