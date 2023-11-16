#ifndef NODE_H
#define NODE_H
#include <cstdlib>
#include <ostream>
#include <iostream>
using namespace std;



// denotes a node of a linked list
// data_ stores the value at the point in the linked list
// link_ stores a pointer to the next node in the linked list (nullptr if it is the last node)
//
// a linked list is give by two node pointers (node<T>*):
//   - the first node pointer points to the head of the linked list
//   - the second node pointer points to the tail of the linked list
//   - if the linked list is empty, both pointers are nullptr
template <typename T>
class node
{
public:
    node(const T & initdata = T(),//By providing default values for parameters, we get
         node * initlink = nullptr){//4 constructors for the price of one
        data_ = initdata;
        link_ = initlink;
    }
    T data() const{
        return data_;
    }
    T data(){
        return data_;
    }
    node * link(){
        return link_;
    }
    const node * link() const{
        return link_;
    }
    void set_data(const T & newdata){
        data_ = newdata;
    }
    void set_link(node * newlink){
        link_ = newlink;
    }
private:
    T data_;
    node * link_;
};


/* linked list toolkit functions */

// return the size of the list
template <typename T>
int list_size(const node<T> * head){
  int count = 0;
  for(const node<T> *temp = head; temp !=nullptr ; temp = (*temp).link()){
    count++;
  }
  return count;
}

// insert a node to the linked list before the head.
template <typename T>
void list_head_insert(node<T>* & head,//Shares memory with the head pointer passed in
                      node<T>* & tail,
                      const T & value){
      head = new node<T>(value, head);
      if(tail==nullptr)
        tail=head;
}

// insert a node to the linked list after the tail.
template <typename T>
void list_tail_insert(node<T> * & head, node<T>* & tail,
    const T & value){
      node<T>* temp = new node<T>(value, nullptr);
      if(tail !=nullptr)
        (*tail).set_link(temp);
      else
        head = temp;
      tail = temp;
    }

// print the linked list
template <typename T>
ostream & operator <<(ostream & os,
  const node<T>* head){
    for(const node<T>* p=head; p!=nullptr; p=(*p).link()){
      os<<(*p).data()<<" ";
    }
    return os;
  }

//Return a pointer to a node with the given value
template <class T>
node<T>* list_search(node<T> * head, const T & value){
    for(node<T>* p=head; p!=nullptr; p=(*p).link()){
      if((*p).data()==value)
        return p;
    }
    return nullptr;
}


// Copy the linked list (orig_head, orig_tail) into a new linked list (new_head, new_tail) 
template <class T>
void list_copy(const node<T> *orig_head,
               const node<T> *orig_tail,
               node<T> * & new_head,
               node<T> * & new_tail){

      //  new_head = orig_head;//Why is this a bad idea?
      //  new_tail = orig_tail;//We want a deep copy!

      for(const node<T>* p=orig_head; p!=nullptr; p=(*p).link()){
        list_tail_insert(new_head, new_tail, (*p).data());
      }
}

// Delete the head node from a linked list
template <class T>
void list_head_remove(node<T> * & head, node<T> * &tail){
    node<T>* temp = (*head).link();
    delete head;
    head=temp;
}

// Delete the node after previous from the linked list
template <class T>
void list_remove(node<T> * previous, node<T> * &tail){
  node<T>* temp = (*previous).link();
  (*previous).set_link((*temp).link());
  delete temp;
}


// Insert a node with value_=value after the node previous in a linked list
template <class T>
void list_insert(node<T> * previous, const T & value){
  node<T>* temp = new node<T>(value, (*previous).link());
  (*previous).set_link(temp);
}


//Delete all memory for the linked list, and reset head and tail to nullptr
template <class T>
void list_clear(node<T> * & head, node<T> * &tail){//HW
      for(node<T>* p = head; p!=nullptr; p=(*p).link()){
        delete p;
      }
      head=nullptr;
      tail = nullptr;
}
#endif // NODE_H
