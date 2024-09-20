#include <iostream>
#include <string>

using namespace std;

// Think: Order the addresses &x, &y, &z from low to high
int foo() {
  int x;
  int y;
  x = 2;
  y = x+2;
  cout << "&x: " << &x << endl;
  cout << "&y: " << &y << endl;
  return y;
}

int bar() {
  int x = 2;
  foo();
  return x+2;
}

int main() {

  bar();
  

  int z=5;
  cout << "&z: " << &z << endl;
}

