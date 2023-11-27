#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "user.h"
#include "network.h"

using namespace std;

int main() {
  Network network;
  User* u = new User(0,"Jason Chen", 2000, 94087, set<int> {1});
  network.addUser(u);
  User* u2 = new User(1,"Issac Boone", 1999, 94305, set<int> {0});
  network.addUser(u2);

  assert(network.getUser(0)->getFriends().size() == 1);
  assert(network.getUser(1)->getFriends().size() == 1);
  network.deleteConnection("Jason Chen", "Issac Boone");
  assert(network.getUser(0)->getFriends().size() == 0);
  assert(network.getUser(1)->getFriends().size() == 0);
}
