#include <iostream>
using namespace std;

class Animal{
  public:
  Animal() {
    cout<<"New Animal"<<endl;
  }
  void sleep(){
    cout<<"Animal sleep"<<endl;
  }
  void eat(){
    cout<<"Animal eat"<<endl;
  }
};
class Bird: public Animal{
  public:
  Bird(){
    cout<<"New Bird!"<<endl;
  }
  void sleep(){
    cout<<"Bird sleeps"<<endl;
  }
};
class Cat: public Animal{
  public:
  Cat(){
    cout<<"New Cat!"<<endl;
  }
  void sleep(){
    Animal::sleep();//Call Animal's sleep method
    cout<<"Cat sleeps"<<endl;
  }
  void meow(){
    cout<<"Meow"<<endl;
  }
};
int main(){
  Animal a;
  Bird b;
  Cat c;

  a.eat();
  a.sleep();
  b.eat();
  b.sleep();
  c.eat();
  c.sleep();
  c.meow();
}
