#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(2,4,"hi",2);
  assert(p.getProfileId() == 2);
  assert(p.getAuthorId() == 4);
}
