#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  IncomingPost p1(0,1,"hello", 2, true, "Lillie Cain");
  string s1 = p1.toString();
  assert(s1.find("hello") != std::string::npos);

  IncomingPost p2(0,1,"hello", 2, false, "Lillie Cain");
  string s2 = p2.toString();
  assert(s2.find("hello") != std::string::npos);
}
