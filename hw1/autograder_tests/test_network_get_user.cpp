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
  User* u = new User(0,"Jason Chen", 2000, 94087, set<int> {1,2,3});
  network.addUser(u);
  assert(network.numUsers() == 1);
  assert(network.getUser(0) != nullptr);
}
