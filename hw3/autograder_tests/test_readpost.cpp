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
  
  assert(n.getPosts(0).size() == 6);
  assert(n.getPosts(2).size() == 10);
  assert(n.getPosts(147).size() == 5);
}
