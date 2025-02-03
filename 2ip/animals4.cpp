#include <iostream>
#include <string>

using namespace std;

class Animal{
  private:
    string name;
  public:
    Animal() { name = ""; }
    Animal(string n) { name = n; }
    string getName() { return name; }
    void setName(string n) { name = n; }
    void sleep(){ cout<<"Animal sleep" <<endl; }
};
class Bird: public Animal{
  public:
    Bird(){ }
    Bird(string n): Animal(n){ }
    void sleep(){ cout<<"Bird sleep"<<endl; }
};
class Cat: public Animal{
  public:
    Cat(){}
    Cat(string n): Animal(n){}
    void sleep(){ cout<<"Cat sleep"<<endl; }
};
int main(){
  vector<Animal> v;
  v.push_back(Animal());
  v.push_back(Bird("Bob")); // cast Bird to Animal before push
  v.push_back(Cat());
  for (Animal x: v) { x.sleep(); }

  Animal a;
  Bird b("Bud");
  a = b;
  b.setName("Bart");
  cout << a.getName() << " " << b.getName() << endl;
}
