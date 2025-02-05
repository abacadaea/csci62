#include <iostream>
using namespace std;

class Item {
public:
  Item() { price = 0; }
  Item(double thePrice) { price = thePrice; }
  virtual double bill() { return price; }
  virtual void print() { cout << "Item. Bill = " << bill() << endl; }
private:
  double price;
};


class DiscountItem : public Item
{
public:
  DiscountItem() { discount = 0; } 
  DiscountItem(double p, double d) : Item (p) { discount = d; }
  double bill() { return (1.0 - discount / 100.0) * Item::bill(); }
  void print() { cout << "DiscountItem. Bill = " << bill () << endl; }
private:
  double discount;
};

bool itemCmp(Item* i1, Item* i2) {
  return i1->bill() < i2->bill();
}

int main()
{
  Item i = Item(10.00);//One item at $10.00.
  cout << i.bill() << endl;

  DiscountItem di = DiscountItem(11.00, 10);//One item at $11.00 with a 10% discount=$9.90
  cout << di.bill() << endl;
  
  //What  happens?
  Item i2 = DiscountItem(11.00, 10);
  cout<<"i2.bill()=" <<i2.bill()<<endl;//bill is the function we want to be able to do polymorphism with

  //What happens?
  Item* ip2 = new DiscountItem(11.00, 10); 
  cout << "ip2->bill()=" << ip2->bill()<<endl;

  vector<Item*> vp;
  vp.push_back(new Item(10));
  vp.push_back(new Item(9));
  vp.push_back(new Item(90));
  vp.push_back(new Item(10));
  vp.push_back(new DiscountItem(100,20));
  vp.push_back(new DiscountItem(100,9));
  vp.push_back(new DiscountItem(110,9));
  vp.push_back(new DiscountItem(11,9));
  vp.push_back(new DiscountItem(10,9));
  cout << "\nBefore sort\n";
  for (Item* i : vp) {
    i->print();
  } 

  sort(vp.begin(), vp.end(), itemCmp);

  cout << "\nAfter sort\n";
  for (Item* i : vp) {
    i->print();
  }
}

