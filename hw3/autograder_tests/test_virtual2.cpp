#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post * p = new Post(3,4,"asdf", 5);
  IncomingPost * ip1 = new IncomingPost(0,1,"hi", 2, true, "Lillie Cain");
  IncomingPost * ip2 = new IncomingPost(0,1,"hi", 2, false, "Lillie Cain");

  assert(p->getIsPublic() == true);
  assert(ip1->getIsPublic() == true);
  assert(ip2->getIsPublic() == false);
}
