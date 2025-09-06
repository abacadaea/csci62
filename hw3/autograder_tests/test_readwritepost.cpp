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
  n.addPost(new Post(1,2,"message1", 2));
  n.addPost(new Post(0,3,"message2", 2));
  n.addPost(new Post(4,5,"message3", 2));
  n.addPost(new LinkPost(1,3,"message4", 2, "http://www.example.com"));
  n.writePosts("tmp.txt");
  
  Network n2;
  n2.readUsers("users.txt");
  n2.readPosts("tmp.txt");

  vector<Post*> v0 = n2.getPosts(0);
  vector<Post*> v1 = n2.getPosts(1);
  vector<Post*> v4 = n2.getPosts(4);

  assert(v0.size() == 1);
  assert(v1.size() == 2);
  assert(v4.size() == 1);
  
  assert(v0[0]->getMessageId() == 1);
  assert(v1[0]->getMessageId() == 0);
  assert(v1[1]->getMessageId() == 3);
  assert(v4[0]->getMessageId() == 2);

  assert(v0[0]->getURL() == "");
  assert(v1[0]->getURL() == "");
  assert(v1[1]->getURL() == "http://www.example.com");
  assert(v4[0]->getURL() == "");


}
