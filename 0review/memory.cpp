#include <iostream>
#include <vector>
#include <string>

using namespace std;

class User {
  public:
    User () {}
    User (string n) { name = n; }
    string getName() { return name; }
  private:
    string name;
};

class Network {
  public:
    Network () {}

    void addUser(string name) {
      //User c1(name);  // on the "stack"
      //users.push_back(&c1); // &c1 will not point to anything meaningful after addUser exists
      User* u1 = new User(name); // on the "heap"
      users.push_back(u1);
    }

    void print() {
      for (auto u : users) {
        cout << u->getName() << endl;
      }
    }
  private:
    vector<User*> users;
};


int main () {
  Network network;
  network.addUser("Alice");
  network.addUser("Bob");
  network.addUser("Charlie");
  network.print();
}
