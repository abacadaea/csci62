#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countA(const char* fname) {
  ifstream fin(fname);
  string word;
  int count = 0;
  while(fin >> word) {
    for (int i = 0; i < word.length(); i ++) {
      if (word[i] == 'A' || word[i] == 'a') {
        count ++;
      }
    }
    /*
    for (char c : word) {
      count += (c=='A');
    }
    */
    cout << word << " " << count << endl;
  }
  return count;
}

int countAByChar(const char* fname) {
  ifstream fin(fname);
  char c;
  int count = 0;
  while(fin >> c) {
    count += (c=='A');
  }
  return count;
}
int countAByLine(const char* fname) {
  ifstream fin(fname);
  string line;
  int count = 0;
  while(getline(fin,line)) {
    for (char c : line) {
      count += (c=='A');
    }
  }
  return count;
}

int main () {
  cout << countA("file.txt") << endl;
  cout << countAByChar("file.txt") << endl;
  cout << countAByLine("file.txt") << endl;
}
