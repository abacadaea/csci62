#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include "user.h"

using namespace std;

int main() {
  User* u = new User(3,"Jason Chen", 2000, 94087, set<int> {0,1,2});
  set<int> & friends = u->getFriends();
  friends.insert(4);

  // u's friends should be updated if friends is pass-by-reference
  assert(u->getFriends().size() == 4);
}
