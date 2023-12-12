#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  IncomingPost p1(0,1,"hi", 2, true, "Lillie Cain");
  assert(p1.getIsPublic() == true);

  IncomingPost p2(0,1,"hi", 2, false, "Lillie Cain");
  assert(p2.getIsPublic() == false);
}
