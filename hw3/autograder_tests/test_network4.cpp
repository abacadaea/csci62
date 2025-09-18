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
  
  // Test with empty user list
  assert(n.numUsers() == 0);
  
  // Test with single user
  User* u = new User(0, "Test User", 2000, 12345, set<int>());
  n.addUser(u);
  assert(n.numUsers() == 1);
  
  // Test adding many posts to same user
  for(int i = 0; i < 1000; i++) {
    n.addPost(new Post(0, 0, "Post " + to_string(i), i));
  }
  vector<Post*> manyPosts = n.getPosts(0);
  assert(manyPosts.size() == 1000);
}
