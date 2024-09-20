#include <iostream>

using namespace std;

int main() {
  int x = 1;
  int y = 2;
  int z = 3;
  cout << "&x: " << &x << endl;
  cout << "&y: " << &y << endl;
  cout << "&z: " << &z << endl;
  // What do you think happens?
  if (&x < &y) {
    cout << "Address of x appears before address of y" << endl;
  } else {
    cout << "Address of y appears before address of x" << endl;
  }
  // Why do &x and &y differ by 4?
  //

  int* aPtr  = new int(5);
  int* bPtr  = new int(10);
  int* cPtr  = new int(10);
  cout << "aPtr: " << aPtr << endl;
  cout << "bPtr: " << bPtr << endl;
  cout << "cPtr: " << cPtr << endl;
  // What do you think happens?
  if (aPtr < bPtr) {
    cout << "aPtr points to earlier address than bPtr" << endl;
  } else {
    cout << "bPtr points to earlier address than aPtr" << endl;
  }
}
