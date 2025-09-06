#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  LinkPost p(130,20,"hiasdfasdfasdfasdfasdfasdf", 2, "http://www.example.com");
  assert(p.getProfileId() == 130);
  assert(p.getAuthorId() == 20);
}
