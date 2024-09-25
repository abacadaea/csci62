#include <iostream>
#include <vector>
#include <set>

using namespace std;


int main () {
  // vector demo
  vector<int> arr;
  arr.push_back(0);
  arr.push_back(0);
  arr.push_back(1);
  arr[1] = 2;
  for (int i = 0; i < arr.size(); i ++) {
    cout << arr [i] << " ";
  }
  cout << endl;
  for (int x: arr) {
    cout << x << " ";
  }
  cout << endl;

  // set demo
  set<int> s;
  s.insert(5);
  s.insert(5);
  s.insert(2);
  s.insert(3);
  cout << s.size() << endl;
  for (auto it: s) {
    cout << it << " ";
  }
  cout << endl;
}
