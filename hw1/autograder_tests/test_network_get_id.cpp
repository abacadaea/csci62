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
  User* u = new User(0,"Jason Chen", 2000, 94087, set<int> {});
  network.addUser(u);
  User* u2 = new User(1,"Issac Boone", 1999, 94305, set<int> {});
  network.addUser(u2);
  assert(network.numUsers() == 2);
  assert(network.getId("Jason Chen") == 0);
  assert(network.getId("Issac Boone") == 1);
  assert(network.getId("Al Smith") == -1);
}
