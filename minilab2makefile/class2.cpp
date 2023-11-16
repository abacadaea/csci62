#include <string>
#include "class2.h"

Class2::Class2 () {
  s = "";
}
Class2::Class2 (std::string s_) {
  s = s_;
}
std::string Class2::getS () {
  return s;
}
