#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  LinkPost p1(1,2,"hi", 2, "http://www.example1234.com");
  assert(p1.getURL() == "http://www.example1234.com");
}
