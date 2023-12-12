#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"
#include "network.h"

using namespace std;

int main() {
  Network n;
  n.readUsers("users.txt");
  n.readPosts("posts.txt");
  
  assert(n.getUser(0)->getPosts().size() == 3);
}
