#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  ifstream fileIn("myfile.txt");
  stringstream strIn("Line from stringstream: blahblah\nblahblah");

  string myLine;
  getline(cin, myLine);
  cout << "getline(cin,myLine): " << myLine << endl;
  getline(fileIn, myLine);
  cout << "getline(fileIn,myLine): " << myLine << endl;
  getline(strIn, myLine);
  cout << "getline(fileIn,myLine): " << myLine << endl;
}
