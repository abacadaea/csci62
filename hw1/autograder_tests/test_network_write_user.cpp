#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "user.h"
#include "network.h"

using namespace std;

int main() {
  char fname[] = "tmp.txt";

  Network network;
  User* u = new User(0,"Jason Chen", 2000, 94087, set<int> {1});
  network.addUser(u);
  User* u2 = new User(1,"Issac Boone", 1999, 94305, set<int> {0});
  network.addUser(u2);

  network.writeUsers(fname);

  Network n2;
  n2.readUsers(fname);
  assert(n2.numUsers() == 2);
  assert(n2.getUser(0)->getName() == "Jason Chen");
  assert(n2.getUser(1)->getName() == "Issac Boone");
  assert(n2.getUser(0)->getFriends().size() == 1);
  assert(n2.getUser(1)->getFriends().size() == 1);
}
