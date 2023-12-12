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
  n.addPost(0,"message1", 2, false, "", false);
  n.addPost(1,"message2", 3, true, "Lillie Cain", false);
  n.addPost(2,"message3", 4, true, "Jeremy Hodges", true);
  n.addPost(0,"message4", 4, true, "Krish Summers", false);
  n.writePosts("tmp.txt");
  
  Network n2;
  n2.readUsers("users.txt");
  n2.readPosts("tmp.txt");

  vector<Post*> v0 = n2.getUser(0)->getPosts();
  vector<Post*> v1 = n2.getUser(1)->getPosts();
  vector<Post*> v2 = n2.getUser(2)->getPosts();

  assert(v0.size() == 2);
  assert(v1.size() == 1);
  assert(v2.size() == 1);
  
  assert(v0[0]->getMessageId() == 0);
  assert(v0[1]->getMessageId() == 3);
  assert(v1[0]->getMessageId() == 1);
  assert(v2[0]->getMessageId() == 2);

  assert(v0[0]->getIsPublic() == true);
  assert(v0[1]->getIsPublic() == false);
  assert(v1[0]->getIsPublic() == false);
  assert(v2[0]->getIsPublic() == true);

  assert(v0[0]->getAuthor() == "");
  assert(v0[1]->getAuthor() == "Krish Summers");
  assert(v1[0]->getAuthor() == "Lillie Cain");
  assert(v2[0]->getAuthor() == "Jeremy Hodges");
}
