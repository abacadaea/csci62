#include <iostream>
using namespace std;
class A{
public:
  A(){ cout << "new A" << endl; }
  void virtual foo(){  cout << "A foo" << endl; }
  void virtual fun(){ cout << "A fun" << endl; }
};
class B: public A{
public:
  B() {  cout << "new B" << endl; }
  void foo(){ cout << "B foo" << endl; }
  void bar(){ cout << "B bar" << endl; }
};
int main(){
  A a1;
  A a2;
  B b1;
  B b2;

  a1=b1;
  b2=a2;
  a1.foo();
  b2.foo();
  a1.bar();
  b2.bar();
  a1.fun();
  b2.fun();

  A* a3=new A();
  A* a4=new B();
  B* b3=new A();
  B* b4=new B();
  
  a3->foo();
  a4->foo();
  b3->foo();
  b4->foo();
  
  a3->bar(); 
  a4->bar();
  b3->bar();
  b4->bar();
  
  a3->fun();
  a4->fun();
  b3->fun();
  b4->fun();
}

