#include <iostream>
#include <string>

using namespace std;

class Animal {
  private: 
    string name;
  public:
    Animal(){
      name = "";
    }
    Animal(string n) {
      name = n;
    }
    virtual void speak () = 0;
};

class Cat : public Animal {
  public:
    Cat () : Animal() {}
    //Cat () { name = ""; } // bad
    Cat (string n) : Animal(n) {}
    //Cat (string n) { name = n; } //bad
    void speak () {
      cout << "Meow!" << endl;
    }
};

class Dog : public Animal {
  public:
    Dog () : Animal() {}
    Dog (string n) : Animal(n) {}
    void speak () {
      cout << "Woof!" << endl;
    }
};


int main () {

  // Also okay, but not preferred because c and d are allocated on stack and disappear after function ends.
  /*
  Dog d;
  Cat c;

  vector<Animal*> v;
  v.push_back(&c);
  v.push_back(&d);
  for (Animal* a : v) {
    a->speak();
  }
  */

  // preferred
  Animal* c = new Cat("Henry");
  Animal* d = new Dog("Spot");
  vector<Animal*> v;
  v.push_back(c);
  v.push_back(d);
  for (Animal* a : v) {
    a->speak();
  }
}
