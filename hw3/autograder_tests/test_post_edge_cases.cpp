#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <sstream>
#include "post.h"

using namespace std;

int main() {
  // Test empty string message
  Post p1(1, 2, "", 0);
  assert(p1.getMessage() == "");
  assert(p1.getLikes() == 0);
  
  // Test very long message
  string longMessage(1000, 'a');
  Post p2(1, 2, longMessage, 1000);
  assert(p2.getMessage() == longMessage);
  assert(p2.getLikes() == 1000);
  
  // Test negative values
  Post p3(-1, -2, "test", -5);
  assert(p3.getProfileId() == -1);
  assert(p3.getAuthorId() == -2);
  assert(p3.getLikes() == -5);
  
  // Test zero values
  Post p4(0, 0, "zero", 0);
  assert(p4.getProfileId() == 0);
  assert(p4.getAuthorId() == 0);
  assert(p4.getLikes() == 0);
  
  // Test special characters in message
  Post p5(1, 2, "Special chars: !@#$%^&*()", 1);
  assert(p5.getMessage() == "Special chars: !@#$%^&*()");
  
  // Test LinkPost with empty URL
  LinkPost lp1(1, 2, "test", 1, "");
  assert(lp1.getURL() == "");
  
  // Test LinkPost with very long URL
  string longURL = "http://" + string(500, 'a') + ".com";
  LinkPost lp2(1, 2, "test", 1, longURL);
  assert(lp2.getURL() == longURL);
}
