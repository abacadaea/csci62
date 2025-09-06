#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(0,1,"asdf",2);
  string s = p.toString();
  assert(s == "asdf (2 likes)");
}
