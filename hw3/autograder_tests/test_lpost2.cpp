#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  LinkPost p(1,2,"hi", 2, "http://www.example.com");
  assert(p.getMessage() == "hi");
  assert(p.getMessageId() == -1);
  assert(p.getProfileId() == 1);
  assert(p.getAuthorId() == 2);
  assert(p.getLikes() == 2);
}
