#include <iostream>

using namespace std;

/* 
 // the usual way
int main () {
  // some code
}
*/


int main(int argc, char *argv[]) {
  cout << "Number of arguments: " << argc << endl;
  for (int i = 0; i < argc; i ++) {
    cout << "Argument " << i << ": " << argv[i] << endl;
  }

  string s; // (C++ string)
  char s2[4]; // char array (C-string)
  char *s3 = s2; // arrays are actually pointers (to the beginning of the array)
  char *strList[4]; // list of 4 strings.
}
