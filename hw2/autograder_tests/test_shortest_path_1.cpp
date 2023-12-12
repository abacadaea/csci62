#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "user.h"
#include "network.h"

using namespace std;

int main() {
  Network net;
  net.readUsers("path5.txt");

  cout << net.shortestPath(4,0).size() << endl;
  assert(net.shortestPath(0,4).size() == 5);
  assert(net.shortestPath(4,0).size() == 5);
  assert(net.shortestPath(1,4).size() == 4);
	return 0;
}
