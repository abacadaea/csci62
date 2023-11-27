#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include "user.h"

using namespace std;

int main () {
  User* u = new User(3,"Jason Chen", 2000, 94087, set<int> {0,1,2});
}

