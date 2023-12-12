#include "dynamicbag.h"
#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
  DynamicBag<int> b;
  b.insert(5);
  b.insert(70);
  for(int i=0; i<5; i++)
      b.insert(i+1);
  cout << b[0] << endl;
  cout<<b<<endl;
  b.erase(5);
  cout<<b<<endl;

  b.sort();
  cout<<b;
}
