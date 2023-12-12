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

  for (int i = 2; i < 5; i ++) {
    int to;
    vector<int> path = net.distanceUser(0,to,i);
    assert(path.size() == i + 1);
    assert(to == i);
  	return 0;
}
	return 0;
}
