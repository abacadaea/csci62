#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  LinkPost p1(1,2,"hello", 2, "http://www.example1234.com");
  string s1 = p1.toString();
  assert(s1.find("hello") != std::string::npos);
}
