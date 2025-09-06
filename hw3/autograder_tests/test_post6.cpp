#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p;
  assert(p.getMessage() == "");
  assert(p.getMessageId() == -1);
  assert(p.getProfileId() == 0);
  assert(p.getAuthorId() == 0);
}
