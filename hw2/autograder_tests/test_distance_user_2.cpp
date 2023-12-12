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
  net.readUsers("cycle5.txt");

  int to;
  vector<int> path = net.distanceUser(2,to,2);
  cout << to << endl;
  assert(to == 0 || to == 4);
	return 0;
}
