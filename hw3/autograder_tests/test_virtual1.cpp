#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post * p = new Post(3,4,"asdf", 5);
  IncomingPost * ip = new IncomingPost(0,1,"hi", 2, true, "Lillie Cain");

  assert(p->getAuthor() == "");
  assert(ip->getAuthor() == "Lillie Cain");
}
