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
  net.readUsers("k4.txt");

  vector<vector<int> > groups = net.groups();
  cout << groups.size() << endl;
  cout << groups[0].size() << endl;
  assert(groups.size() == 1);
  assert(groups[0].size() == 4);
	return 0;
}
