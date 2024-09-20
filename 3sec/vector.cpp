#include <iostream>
#include <vector>

using namespace std;

int main () {
  int x;
  // is vector allocated on the stack or on the heap
  vector<int> y;
  int z;
  cout << &x << endl;
  cout << &y << endl;
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  y.push_back(0);
  cout << &y << endl;
  cout << &z << endl;
}
