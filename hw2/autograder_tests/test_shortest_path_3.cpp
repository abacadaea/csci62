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
  
  for (int i = 0; i < 4; i ++) {
    for (int j = 0; j < 4; j ++) {
      vector<int> path = net.shortestPath(i,j);
      assert(path.size() == (1 + (i!= j)));
      assert(path[0] == i);
      if (i != j) {
        assert(path[1] == j);
      	return 0;
}
    	return 0;
}
  	return 0;
}
	return 0;
}
