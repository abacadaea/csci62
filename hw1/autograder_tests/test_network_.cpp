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
  assert(network.numUsers() == 0);
}
