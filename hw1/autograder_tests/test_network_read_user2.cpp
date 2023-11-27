#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "user.h"
#include "network.h"

using namespace std;

int main() {
  char fname[] = "cycle5.txt";
  Network network;
  network.readUsers(fname);
  assert(network.numUsers() == 5);
  assert(network.getUser(0)->getId() == 0);
  assert(network.getUser(0)->getName() == "Aled Montes");
  assert(network.getUser(0)->getYear() == 2009);
  assert(network.getUser(0)->getZip() == 47309);
  assert(network.getUser(0)->getFriends().size() == 2);

  for (int i = 0; i < 5; i ++) {
    assert(network.getUser(i)->getId() == i);
  }
}
