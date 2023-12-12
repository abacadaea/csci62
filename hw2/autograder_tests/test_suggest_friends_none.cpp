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

  int score;
  vector<int> suggestions = net.suggestFriends(1,score);
    cout << suggestions.size() << " " << score << endl;
    for (auto v : suggestions) { cout << v << endl;	return 0;
}
  assert(suggestions.size() == 0);
	return 0;
}
