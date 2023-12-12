#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  IncomingPost p(0,1,"hi", 2, true, "Lillie Cain");
  assert(p.getAuthor() == "Lillie Cain");
}
