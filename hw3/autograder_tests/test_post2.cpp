#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  Post p(1,2,"hi",2);
  assert(p.getMessageId() == -1);
}
