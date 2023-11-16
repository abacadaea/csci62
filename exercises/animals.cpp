#include <iostream>
using namespace std;

class Animal{
  private:
    string name;
  public:
  Animal() {
    name = "";
    cout<<"New Animal!"<<endl;
  }
  Animal(string n) {
    name = n;
    cout<<"New Animal: "<<name<<endl;
  }
  string getName(){return name;}
  void sleep(){
    cout<<"Animal sleeps ..."<<name<<endl;
  }
  void eat(){
    cout<<"Animal eats ..."<<name<<endl;
  }
};
class Bird: public Animal{
  public:
  Bird(){
    cout<<"New Bird!"<<endl;
  }
  Bird(string n): Animal(n){
    cout<<"New Bird!"<<endl;
  }
  void sleep(){
    cout<<"Bird sleeps ..."<<getName()<<endl;
  }
};
class Cat: public Animal{
  public:
  Cat(){
    cout<<"New Cat!"<<endl;
  }
  Cat(string n): Animal(n){
    cout<<"New Cat!"<<endl;
  }
  void sleep(){
    Animal::sleep();//Call Animal's sleep method
    cout<<"Cat sleeps ..."<<getName()<<endl;
  }
  void meow(){
    cout<<"Meow!!"<<endl;
  }
};
int main(){
  Cat c1;
  Cat c2("Henry the Cat");
  Animal a1;
  Animal a2("Spot the Giraffe");
  Bird b;

  a2.eat();
  a2.sleep();
  b.eat();
  b.sleep();
  c2.eat();
  c2.sleep();
  c2.meow();
}
