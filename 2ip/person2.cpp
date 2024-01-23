// More inheritance practice:
// Cross out the lines in main() that don't compile and predict what is printed out.
// Check your answers by actually compiling and running the code
#include <iostream>
#include <string>

using namespace std;

class Person{
  private: 
    string name;
  public:
    Person() {
      name = "";
      cout << "New Person" << endl;
    }
    Person(string n) {
      name = n;
      cout << "New Person: " << n << endl;
    }
    void foo () {
      cout << "Person foo" << endl;
    }
    void bar () {
      cout << "Person bar" << endl;
    }
    string toString(){
      return name;
    }
};
class Customer: public Person{
  public:
    Customer(): Person ("Anonymous"){ 
      cout << "New Customer" << endl;
    }
    Customer(string n): Person(n){
      cout << "New Customer" << endl;
    }
    void foo () {
      cout << "Customer foo" << endl;
    }
    void baz () {
      cout << "Customer baz" << endl;
    }
    string toString() {
      return "Customer " + Person::toString();
    }
};

int main(){
  Person p;
  Customer c; 

  p = c;
  c = p;

  p.foo();
  c.foo();

  p.bar();
  c.bar();

  p.baz();
  c.baz();
}
