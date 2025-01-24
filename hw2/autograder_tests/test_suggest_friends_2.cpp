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
    assert(suggestions.size() == 2);
    int s1 = (i+2)%5;
    int s2 = (i+3)%5;
    assert(suggestions[0] + suggestions[1] == s1+s2);
    assert(suggestions[0] * suggestions[1] == s1*s2);
  }
	return 0;
}
