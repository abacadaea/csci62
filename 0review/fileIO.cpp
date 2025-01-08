#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string myLine, myWord;

  // standard input
  //cin >> myWord; // standard input
  //cout << "cin>>myWord: " << myWord << endl;
  //cin >> myWord; // standard input
  //cout << "cin>>myWord: " << myWord << endl;

  // file input 
  //ifstream fileIn("myfile.txt");
  //fileIn >> myWord; 
  //cout << "fileIn>>myWord: " << myWord << endl;
  //fileIn >> myWord; 
  //cout << "fileIn>>myWord: " << myWord << endl;
  //fileIn >> myWord; 
  //cout << "fileIn>>myWord: " << myWord << endl;
  //fileIn >> myWord; 
  //cout << "fileIn>>myWord: " << myWord << endl;
  
  // getline
  //getline(cin, myLine);
  //cout << "getline(cin,myLine): " << myLine << endl;
  //getline(cin, myLine);
  //cout << "getline(cin,myLine): " << myLine << endl;
  //getline(cin, myLine);
  //cout << "getline(cin,myLine): " << myLine << endl;

  //ifstream fileIn("myfile.txt");
  //getline(fileIn, myLine);
  //cout << "getline(fileIn,myLine): " << myLine << endl;
  //getline(fileIn, myLine);
  //cout << "getline(fileIn,myLine): " << myLine << endl;
  //getline(fileIn, myLine);
  //cout << "getline(fileIn,myLine): " << myLine << endl;
  //getline(fileIn, myLine);
  //cout << "getline(fileIn,myLine): " << myLine << endl;
  //getline(fileIn, myLine);
  //cout << "getline(fileIn,myLine): " << myLine << endl;

  //ifstream fileIn("myfile2.txt");
  //int x, sum = 0;
  //while(fileIn  >> x) { // read until no numbers left to read
  //  sum += x;
  //  cout << "x=" << x << ", sum=" << sum << endl;
  //}
  //cout << "sum=" << sum << endl;

  // string input
  int x, sum = 0;
  stringstream strIn("1 2 1 2");
  while(strIn  >> x) {
    sum += x;
  }
  cout << "sum=" << sum << endl; 
}
