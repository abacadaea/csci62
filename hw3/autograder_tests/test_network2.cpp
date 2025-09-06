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
  n.addPost(new Post(0,3,"message2", 3));
  n.addPost(new Post(4,5,"message3", 5));
  n.addPost(new LinkPost(1,3,"message4", 4, "http://www.example.com"));

  vector<Post*> v0 = n.getPosts(0);
  vector<Post*> v1 = n.getPosts(1);
  vector<Post*> v4 = n.getPosts(4);

  assert(v0.size() == 1);
  assert(v1.size() == 2);
  assert(v4.size() == 1);
  
  assert(v0[0]->getMessageId() == 1);
  assert(v1[0]->getMessageId() == 0);
  assert(v1[1]->getMessageId() == 3);
  assert(v4[0]->getMessageId() == 2);

  string s = n.postDisplayString(v4[0]);
  assert(s.substr(0,15) == "Qiu Dong wrote:");
  assert(s.find("message3") != string::npos);
  assert(s.find("5 likes") != string::npos);


  s = n.postDisplayString(v1[0]);
  assert(s.substr(0,20) == "Haaris George wrote:");
  assert(s.find("message1") != string::npos);
  assert(s.find("2 likes") != string::npos);

  s = n.postDisplayString(v1[1]);
  assert(s.substr(0,18) == "Alysha Gray wrote:");
  assert(s.find("message4") != string::npos);
  assert(s.find("4 likes") != string::npos);
  assert(s.find("http://www.example.com") != string::npos);
}
