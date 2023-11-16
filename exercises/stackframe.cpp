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






  //cout << str1 << endl;
  //cout << str2 << endl;
  //cout << str3 << endl;
  //cout << str4 << endl;
  //cout << &str1 << endl;
  //cout << &str2 << endl;
  //cout << &str3 << endl;
  //cout << &str4 << endl;

  /*
  int i;
  for (i = 0; i < 42; i ++) {
    cout << int(str4[i]) << " " << str4[i] << endl;
  }*/
