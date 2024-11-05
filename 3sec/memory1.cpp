#include <iostream>

using namespace std;

int main() {
  int x = 1;
  int y = 2;
  int z = 3;
  cout << "&x: " << &x << endl;
  cout << "&y: " << &y << endl;
  cout << "&z: " << &z << endl;
  // How much do &x and &y diff by?
  // What do you think happens?
  if (&x < &y) {
    cout << "address of x < address of y" << endl;
  } else {
    cout << "address of x > address of y" << endl;
  }

  int* aPtr  = new int(5);
  int* bPtr  = new int(10);
  int* cPtr  = new int(10);
  cout << "aPtr: " << aPtr << endl;
  cout << "bPtr: " << bPtr << endl;
  cout << "cPtr: " << cPtr << endl;
  // What do you think happens?
  if (aPtr < bPtr) {
    cout << "aPtr < bPtr" << endl;
  } else {
    cout << "aPtr > bPtr" << endl;
  }
}
