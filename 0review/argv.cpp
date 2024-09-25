#include <iostream>

using namespace std;

/* 
 // the usual way
int main (int argc, char* argv[]) {
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
  char *s3 = s2; // C-strings are actually char-pointers (that point to the string)
}
