#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  LinkPost p1(13,24,"hello42", 2, "http://www.example1234.com");
  assert(p1.toString() == "hello42 (url: http://www.example1234.com) (2 likes)");
}
