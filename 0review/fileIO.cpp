#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string myLine, myWord;

  // standard input
  cin >> myWord; // standard input
  cout << "cin>>myWord: " << myWord << endl;

  // file input 
  ifstream fileIn("myfile.txt");
  fileIn >> myWord; 
  cout << "fileIn>>myWord: " << myWord << endl;

  // string input
  stringstream strIn("    apple \t orange\nbanana blueberry");
  strIn >> myWord; // string input (stringstream)
  cout << "strIn>>myWord: " << myWord << endl;
  strIn >> myWord; // string input (stringstream)
  cout << "strIn>>myWord: " << myWord << endl;
  strIn >> myWord; // string input (stringstream)
  cout << "strIn>>myWord: " << myWord << endl;

  // getline
  /*
  getline(cin, myLine);
  cout << "getline(cin,myLine): " << myLine << endl;

  ifstream fileIn("myfile.txt");
  getline(fileIn, myLine);
  cout << "getline(fileIn,myLine): " << myLine << endl;
  getline(fileIn, myLine);
  cout << "getline(fileIn,myLine): " << myLine << endl;
  getline(fileIn, myLine);
  cout << "getline(fileIn,myLine): " << myLine << endl;
  getline(fileIn, myLine);
  cout << "getline(fileIn,myLine): " << myLine << endl;

  stringstream strIn("apple orange\nbanana blueberry");
  getline(strIn, myLine);
  cout << "getline(strIn,myLine): " << myLine << endl;
  */

  /*
  ifstream fileIn("myfile2.txt");
  int x, sum = 0;
  while(fileIn  >> x) {
    sum += x;
    cout << "x=" << x << ", sum=" << sum << endl;
  }
  cout << "sum=" << sum << endl;

  stringstream strIn("1 2\n 1 2");
  sum = 0;
  while(strIn  >> x) {
    sum += x;
  }
  cout << "sum=" << sum << endl; 
  */
}
