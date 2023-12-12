#include <iostream>
using namespace std;

class Animal{
  private:
    string name;
  public:
  Animal() {
    name = "";
  }
  Animal(string n) {
    name = n;
  }
  virtual void sleep(){
    cout<<"Animal sleep" <<endl;
  }
  void eat(){
    cout<<"Animal eat"<<endl;
  }
};
class Bird: public Animal{
  public:
  Bird(){ }
  Bird(string n): Animal(n){ }
  void sleep(){
    cout<<"Bird sleep"<<endl;
  }
  void eat(){
    cout<<"Bird eat"<<endl;
  }
};
class Cat: public Animal{
  public:
  Cat(){}
  Cat(string n): Animal(n){}
  void sleep(){
    cout<<"Cat sleep"<<endl;
  }
  void meow(){
    cout<<"Meow!!"<<endl;
  }
};

int main(){
  Animal a;
  Bird b;
  Cat c;

  a=c;  //Treat a cat object like an animal?
        //Equivalent: a1 = (Animal)c2;
  //c=a;//Treat an animal object like a cat?
   
  a.eat();
  a.sleep();
  //a.meow();
  
  vector<Animal> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(c);
  cout << endl;
  for (auto x: v) {
    x.sleep(); // all objects get cast as Animal
  }     

  cout << endl;
  Animal* ap0 = new Cat();
  ap0->sleep();//Calls Cat's sleep
  ap0->eat();
  //ap->meow();//Can only do Animal things while treating like an Animal

  Animal* ap = new Animal();
  Bird* bp = new Bird();
  Cat* cp = new Cat();
  
  vector<Animal*> vp;
  vp.push_back(ap);
  vp.push_back(bp);
  vp.push_back(cp);
  cout << endl;
  for (auto x: vp) {
    x->sleep();
  }
  cout << endl;
  for (auto x: vp) {
    x->eat();
  }
}
