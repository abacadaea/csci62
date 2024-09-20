#include <iostream>
#include <string>
#include <vector>

using namespace std;

class User{
  private:
    string name;
  public:
    User() { name = ""; }
    User(string n) { name = n; }
    void print() { cout << "User: " << name << endl; }
}
;

class Network {
  private:
    vector<User*> users;
  public:
    Network() {users.clear();}
    void addUser(string name) {
      // will both of these work?
      User u(name); // user allocated on the stack
      users.push_back(&u); 
      cout << "Added user stored in memory address " << &u << endl;
      
      User* uPtr = new User(name);  // user allocated on the heap
      users.push_back(uPtr);
      cout << "Added user stored in memory address " << uPtr << endl;
    }
    void print() {
      for (auto uPtr : users) {
        uPtr->print();
      }
    }
};

int main () {
  Network n;
  n.addUser("Alice");
  n.addUser("Bob");
  n.addUser("Charlie");
  n.print();
}
