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

  for (int i = 0; i < 5; i ++) {
    int score;
    vector<int> suggestions = net.suggestFriends(i,score);
    cout << suggestions.size() << " " << score << endl;
    for (auto v : suggestions) { cout << v << endl;	return 0;
}
    assert(score == 1);
  	return 0;
}
	return 0;
}
