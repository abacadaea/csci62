#include <iostream>
#include <string>

using namespace std;

string globalString="HI";

void foo() {
  int x = 5;
  cout << &x << endl;
  int* yPtr = &x;
  for(int i = 0; i < 20; i ++) {
    cout << *(yPtr+i) << endl;
  }
}

int main() {
  string s = "HEY THERE";
  string* sPtr = new string("HEY THERE");
  int i=100;
  //cout << sPtr << endl;
  foo();
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
