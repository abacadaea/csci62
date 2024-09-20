#include <iostream>
#include <string>

using namespace std;

int bar(int a) {
  int x = 2*a;
  cout << "&a: " << &a << endl;
  cout << "&x: " << &x << endl;
  return x;
}

int foo(int a, int b) {
  int x;
  int y;
  cout << "&a: " << &a << endl;
  cout << "&b: " << &b << endl;
  cout << "&x: " << &x << endl;
  cout << "&y: " << &y << endl;
  x = a;
  y = bar(b);
  return x+y;
}

int main() {
  int a=5;
  cout << "&a: " << &a << endl;
  foo(2,3);
}
