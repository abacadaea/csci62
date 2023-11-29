#include <iostream>

using namespace std;

class A {
  private:
    vector<int> vec;
  public:
    A() {}
    vector<int> getVec () { return vec; };
    vector<int> & getVecRef () { return vec; };
};

int main () {
  A a;
  vector<int> v = a.getVec();
  v.push_back(1);
  // the next line prints 0.
  // a's vector is still empty, because getVec returned a value
  cout << a.getVec().size() << endl; 

  vector<int> v2 = a.getVecRef();
  v2.push_back(1);
  // the next line prints 0. Even though getVecRef returned a referencee, 
  // v2 is not a reference to a vector, so v2 is a copy of the vector
  cout << a.getVec().size() << endl; 


  vector<int> & v3 = a.getVecRef();
  v3.push_back(1);
  // the next line prints 1. v3 is a reference to a's vec, so the above line changes a.vec
  cout << a.getVec().size() << endl; 
}

