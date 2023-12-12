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


  string s = p->toString();
  string is1 = ip1->toString();
  string is2 = ip2->toString();

  assert(s.substr(0,4) == "asdf");
  assert(is1.substr(0,18) == "Lillie Cain wrote:");
  assert(is2.find("(private)") != std::string::npos);
}
