#include <iostream>
#include <fstream>

using namespace std;

// AAaa A hi

int countWordA(const char* fname) {
  int count = 0;
  ifstream fin (fname);
  string s;

  while (fin >> s) {
    if (s == "A") 
      count++;
  }
  return count;
}

int countA(const char* fname) {
  int count = 0;
  ifstream fin (fname);
  string s;

  while (fin >> s) {
    for (int i = 0; i < s.length(); i ++) {
      if (s[i] == 'A' || s[i] == 'a') 
        count ++;
    }
    /*
    for (char c: s) {
      count += (c == 'A'); // true -> 1, false -> 0
      //if (c == 'A') 
      //  count ++;
    }
    */
  }

  /*
  while (getline(fin, s)) {
    for (char c: s) {
      count += (c == 'A'); // true -> 1, false -> 0
    }
  }
  */

  /*
  char c;
  while (fin >> c) {
    count += (c == 'A');
  }
  */

  return count;
}

int main () {
  cout << "countA(\"myfile.txt\") = " << countA("myfile.txt") << endl;
  cout << "countWordA(\"myfile.txt\") = " << countWordA("myfile.txt") << endl;
}
