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
  
  // Test that posts are properly managed when added to network
  Post* p1 = new Post(1, 2, "test1", 1);
  Post* p2 = new LinkPost(1, 2, "test2", 1, "http://example.com");
  
  n.addPost(p1);
  n.addPost(p2);
  
  // Test that we can retrieve and use the posts
  vector<Post*> posts = n.getPosts(1);
  assert(posts.size() == 2);
  assert(posts[0]->getMessage() == "test1");
  assert(posts[1]->getMessage() == "test2");
  
  // Test that posts persist after creation
  for(int i = 0; i < 100; i++) {
    n.addPost(new Post(1, 1, "persistent " + to_string(i), i));
  }
  
  vector<Post*> manyPosts = n.getPosts(1);
  assert(manyPosts.size() == 102); // 2 original + 100 new
  
  // Test that toString() doesn't cause memory issues
  for(Post* post : manyPosts) {
    string str = post->toString();
    assert(!str.empty());
  }
}
