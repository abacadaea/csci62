#include <iostream>

using namespace std;

int main() {
  char str1[] = "HEY THERE";
  char str2[] = "ALOHA!";
  char str3[] = "HELLO WORLD";

  cout << "Before:\n";
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;

  cout << "\nAddresses:\n";
  cout << "str1: " << &str1 << endl;
  cout << "str2: " << &str2 << endl;
  cout << "str3: " << &str3 << endl;

  int i;
  for (i = 0; str3[i]!='\0'; i++) {  // until the end of str4
    str2[i] = str3[i];
  }
  str2[i] = str3[i]; // copies \0
  cout << "\nAfter:\n";
  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;
}
