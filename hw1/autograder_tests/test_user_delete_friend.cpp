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
  assert(u->getFriends().size() == 3);
  u->deleteFriend(0);
  assert(u->getFriends().size() == 2);
  u->deleteFriend(0);
  assert(u->getFriends().size() == 2);
  u->deleteFriend(1);
  assert(u->getFriends().size() == 1);
  u->deleteFriend(2);
  assert(u->getFriends().size() == 0);
  u->deleteFriend(2);
  assert(u->getFriends().size() == 0);
}
