#include <iostream>

using namespace std;

int main() {
  char str1[] = "HEY THERE";
  char str2[] = "ALOHA!";
  char str3[] = "HOWDY";
  char str4[] = "HELLO WORLD";

  cout << "Before:\n";
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
  cout << "str4: " << str4 << endl;

  int i;
  for (i = 0; str4[i]!='\0'; i++) {  // until the end of str3
    str2[i] = str4[i];
  }
  cout << "\nAfter:\n";
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
  cout << "str4: " << str4 << endl;

  for (i = 0; str4[i]!='\0'; i++) {  // until the end of str3
    str3[i] = str4[i];
  }
  cout << "\nAfter:\n";
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
  cout << "str4: " << str4 << endl;
}
