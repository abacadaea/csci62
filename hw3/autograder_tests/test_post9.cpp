#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(0,1,"hi",2);
  string s = p.toString();
  assert(s.find("hi") != std::string::npos);
  assert(s.find("Liked by 2 people") != std::string::npos);
}
