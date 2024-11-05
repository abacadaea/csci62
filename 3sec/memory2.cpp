#include <iostream>
#include <string>

using namespace std;

int bar(int x) {
  int y = 2*x;
  cout << "&x=" << &x << endl;
  cout << "&y=" << &y << endl;
  return y;
}

int foo(int b, int c) {
  int p=b;
  int q=bar(c);
  cout << "&b=" << &b << endl;
  cout << "&c=" << &c << endl;
  cout << "&p=" << &p << endl;
  cout << "&q=" << &q << endl;
  return p+q;
}

int main() {
  int a=5;
  cout << "&a=" << &a << endl;
  foo(2,3);
}
