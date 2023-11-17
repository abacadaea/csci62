#include <iostream>

using namespace std;

void doStuff(int a, int &b) {
  a = 1;
  b = 1;
}

int main () {
  int aa = 50;
  int bb = 50;
  doStuff(aa, bb);
  cout << aa << " " << bb << endl; // prints "50 1"
}

