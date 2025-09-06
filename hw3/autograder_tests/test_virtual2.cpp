#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post * p = new Post(3,4,"asdf", 5);
  LinkPost * lp1 = new LinkPost(2,1,"hiasdf",2, "http://www.example.com");
  LinkPost * lp2 = new LinkPost(2,1,"hihihi",4, "http://www.example2.com");

  assert(p->toString() == "asdf (5 likes)");
  assert(lp1->toString() == "hiasdf (url: http://www.example.com) (2 likes)");
  assert(lp2->toString() == "hihihi (url: http://www.example2.com) (4 likes)");
}
