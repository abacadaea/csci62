#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(0,1,"hi",2);
  assert(p.getLikes() == 2);
}
