#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(0,1,"hello",2);
  assert(p.getMessage() == "hello");
}
