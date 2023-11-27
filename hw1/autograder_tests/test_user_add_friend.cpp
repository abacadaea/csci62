#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include "user.h"

using namespace std;

int main() {
  User* u = new User(1,"Jason Chen", 2000, 94087, set<int> ());
  u->addFriend(2);
  assert(u->getFriends().size() == 1);

  u->addFriend(3);
  assert(u->getFriends().size() == 2);
  
  set<int> f = u->getFriends();
  assert(f.find(2) != f.end() );
  assert(f.find(3) != f.end() );
  assert(f.find(0) == f.end() );
  assert(f.find(1) == f.end() );
}
