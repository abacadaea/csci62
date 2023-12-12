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
  net.readUsers("empty4.txt");

  for (int i = 0; i < 4; i ++) {
    for (int j = 0; j < i; j ++) {
      assert(net.shortestPath(i,j).size() == 0);
      assert(net.shortestPath(j,i).size() == 0);
    	return 0;
}
  	return 0;
}
	return 0;
}
