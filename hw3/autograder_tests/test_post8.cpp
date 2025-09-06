#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(0,1,"hello",2);
  string s = p.toString();
  assert(s.find("hello") != std::string::npos);
  assert(s.find("(2 likes)") != std::string::npos);
}
