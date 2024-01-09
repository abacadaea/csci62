#ifndef DYNAMICBAG_H
#define DYNAMICBAG_H

#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <iostream>
#include "sortable.h"



// DynamicBag is a "template class"
// vector<> is an example of a template class
// vector<int> v, creates a vector that stores ints.
// DynamicBag<int> b creates a DynamicBag that stores ints.
template <typename T>
/*class DynamicBag: public Sortable<T>*/
class DynamicBag : public Sortable<T>
{
public:
    typedef std::size_t size_type;
    void sort() {
      this->quickSort(0, size()-1);
    }

    // CONSTRUCTOR & DESTRUCTOR

    // default constructor
    // pre: none
    // post: creates an empty DynamicBag
    DynamicBag();

    // copy constructor
    // pre: none
    // post: creates a new DynamicBag which is a copy of the given one
    DynamicBag(const DynamicBag &b);

    // pre: none
    // post: destroys this DynamicBag; needed because we are using
    //       dynamically allocated memory
    ~DynamicBag();

    // CONSTANT MEMBERS
    // pre: none
    // post: returns the number of elements in this DynamicBag
    size_type size() const {return used_;}

    // pre: none
    // post: returns the number of times entry appears in this DynamicBag
    size_type count(T entry) const;

    //pre:  pos<capacity_
    //post:  returns the pos(th) item in the bag.
    T& operator [](size_type pos);

    // MUTATING MEMBERS

    // pre: none
    // post: adds a copy of target to this DynamicBag
    void insert(T target);

    // pre: none
    // post: adds to this DynamicBag a copy of each element of b
    void operator += (const DynamicBag & b);

    // pre: none
    // post: if target appears in this DynamicBag, remove one copy and
    //       return true; else return false

    bool erase_one(T target);

    // pre: none
    // post: removes every copy of target in this DynamicBag and
    //       returns the number of elements removed
    size_type erase(T target);

    // pre: none  (NEW!  Before we used the built-in one)
    // post: makes this bag a copy of b
    void operator =(const DynamicBag &b);

private:
    T *data_;
    size_type capacity_;
    size_type used_;

    // INVARIANTS:
    //   data_ points a dynamically allocated array of size capacity_
    //   data_[0], data_[1], ..., data_[used_-1] store the elements
    //   of this DynamicBag
    //   we don't care about data_[used_], ..., data_[capacity_]


};

// pre: none
// post: returns the sum of a and b
template <typename T>
DynamicBag<T> operator +(const DynamicBag<T> & a, const DynamicBag<T> & b);

template <typename T>
std::ostream& operator<<(std::ostream&  out, DynamicBag<T>& b);
//-----------------------------------------------------------------
template <typename T>
DynamicBag<T>::DynamicBag(){
  used_ = 0;
  capacity_ = 0;
  data_ = nullptr;
}

template <typename T>
DynamicBag<T>::DynamicBag(const DynamicBag &b){
  used_ = b.used_;
  capacity_ = b.capacity_;
  data_ = new T[capacity_];
  for(size_type i = 0; i<used_; ++i){
    data_[i] = b[i];
  }
}

template <typename T>
void DynamicBag<T>::operator =(const DynamicBag &b){
  if(this==&b){
    return;
  }
  else{
    used_ = b.used_;
    capacity_ = b.capacity_;
    delete [] data_;
    data_ = new T[capacity_];
    for(size_type i = 0; i<used_; ++i){
      data_[i] = b[i];
    }
  }
}



template <typename T>
DynamicBag<T>::~DynamicBag(){
    delete [] data_;
    data_ = nullptr;
    capacity_ = 0;
    used_ = 0;
}

 template <typename T>
T& DynamicBag<T>::operator [](size_type pos) {
  assert(pos<capacity_);
  return data_[pos];
}

template <typename T>
typename DynamicBag<T>::size_type DynamicBag<T>::count(T target) const{
  size_type count = 0;
  for(size_type i = 0; i<used_; ++i){
    if(data_[i]==target)
      ++count;
  }
  return count;
}

 template <typename T>
void DynamicBag<T>::insert(T target){
  if(used_>=capacity_){
    int newsize = 0;
    if(capacity_ ==0)
      newsize = 1;
    else
      newsize = capacity_*2;
    T * temp = new T[newsize];
    for(std::size_t i = 0; i<used_; ++i){
      temp[i] = data_[i];
    }
    delete [] data_;
    data_ = temp;
    temp = nullptr;
    capacity_ = newsize;

  }
  data_[used_] = target;
  ++used_;
}


template <typename T>
void DynamicBag<T>::operator += (const DynamicBag & b){
}


 template <typename T>
bool DynamicBag<T>::erase_one(T target){
  size_type i = 0;
  for(i = 0; i<used_ &&data_[i]!=target; ++i){
  }
  if(i==used_)
    return false;
  else{
    for(size_type j = i; j<used_-1; ++j){
      data_[j] = data_[j+1];
    }
    --used_;
    return true;
  }
  if(used_<.25*capacity_){
    T* temp = new T[capacity_/2];
    for(size_type i = 0; i<used_; ++i)
      temp[i] = data_[i];
    delete [] data_;
    data_ = temp;
    temp = nullptr;
    capacity_ = .5*capacity_;
  }
}


template <typename T>
typename DynamicBag<T>::size_type  DynamicBag<T>::erase(T target)
{
  size_type count = 0;
  while(erase_one(target)){++count;}
  return count;
}


template <typename T>
DynamicBag<T> operator + (const DynamicBag<T> & b1, const DynamicBag<T> & b2){
  DynamicBag<T> b;
  for(typename DynamicBag<T>::size_type i = 0; i<b1.size(); ++i)
    b.insert(b1[i]);
  for(typename DynamicBag<T>::size_type i = 0; i<b2.size(); ++i)
    b.insert(b2[i]);
  return b;
}

template <typename T>
std::ostream& operator<<(std::ostream&  out, DynamicBag<T>& b){
  for(typename DynamicBag<T>::size_type i = 0; i<b.size(); ++i)
    out<<b[i]<< " ";
  out<<std::endl;
  return out;
}



#endif // DYNAMICBAG_H
