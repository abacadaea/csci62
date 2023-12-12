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
  net.readUsers("match4.txt");

  vector<vector<int> > groups = net.groups();
  assert(groups.size() == 2);
  assert(groups[0].size() == 2);
  assert(groups[1].size() == 2);
	return 0;
}
