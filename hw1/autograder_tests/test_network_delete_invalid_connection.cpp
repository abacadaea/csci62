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
  User* u1= new User(0,"Jason Chen", 2000, 94087, set<int> {});
  User* u2= new User(1,"Issac Boone", 2000, 94087, set<int> {});
  network.addUser(u1);
  network.addUser(u2);
  assert(network.deleteConnection("Jason Chen", "Al Smith") == -1);
}
