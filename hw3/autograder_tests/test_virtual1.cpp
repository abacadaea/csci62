#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post * p = new Post(3,4,"asdf", 5);
  LinkPost * lp = new LinkPost(2,1,"hi",2, "http://www.example.com");

  assert(p->getURL() == "");
  assert(lp->getURL() == "http://www.example.com");
}
