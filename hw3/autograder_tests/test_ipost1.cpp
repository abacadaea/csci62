#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  IncomingPost p;
  assert(p.getMessage() == "");
  assert(p.getMessageId() == 0);
  assert(p.getOwnerId() == 0);
  assert(p.getLikes() == 0);
}
