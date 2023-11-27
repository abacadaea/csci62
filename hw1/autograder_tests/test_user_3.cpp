#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include "user.h"

using namespace std;

int main () {
  User* u = new User(3,"Jason Chen", 2000, 94087, set<int> {});
  assert(u->getId() == 3);
  assert(u->getName() == "Jason Chen");
  assert(u->getYear() == 2000);
  assert(u->getZip() == 94087);
}

