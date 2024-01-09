#include <iostream>
#include <string>

using namespace std;

// Think: Order the addresses &z, &a, &b, &x, &y from low to high
int add(int a, int b) {
  int x;
  int y;
  x = a;
  y = x + b;
  cout << "&a: " << &a << endl;
  cout << "&b: " << &b << endl;
  cout << "&x: " << &x << endl;
  cout << "&y: " << &y << endl;
  return y;
}

int main() {
  int z=5;
  cout << "main: &z: " << &z << endl;

  add(2,3);
}

