#include <iostream>
#include <string>

using namespace std;

class Person{
  private: 
    string name;//Private fields not accessible from child class

  public:
    Person() {
      name = "";
      cout << "New Person" << endl;
    }
    Person(string n) {
      name = n;
      cout << "New Person: " << n<< endl;
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
class Employee: public Person{
  private:
    int id;
  public:
    Employee(){ // implicitly calls the Person constructor
      cout << "New Employee" << endl;
    }
    Employee(string n, int i): Person(n){
      //name = n;//Can't directly access, but could if it was protected instead of private
      id = i;
      cout << "New Employee" << endl;
    }
    void foo () {
      cout << "Employee foo" << endl;
    }
    void pay () {
      cout << "Employee pay" << endl;
    }
    string toString() {
      //return "Employee " + name + ", ID: " + std::to_string(id);
      return "Employee " + Person::toString() + ", ID: " + std::to_string(id);
    }
};


int main(){
  Person p0;
  Employee e0; 
  Person p1("Alice in Wonderland");
  Employee e1("Spongebob Squarepants",1);

  p0.foo();
  e0.foo();

  p0.bar();
  e0.bar(); // can we still call this?

  //p0.pay();
  //e0.pay();

  cout << p1.toString() << endl;
  cout << e1.toString() << endl;

  /*
  // which one compiles?
  p0 = e0;
  e0 = p0;
  */
}
