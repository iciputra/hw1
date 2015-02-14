#include "setint.h"
#include <cstdlib>

  SetInt::SetInt(){
    ptr_f = NULL;
    ptr_n = NULL;
    increment = 0;
  }

  SetInt::~SetInt(){} //check llistint.cpp

  int SetInt::size() const{
     return this->list_.size();
  }

  bool SetInt::empty() const{
      if (list_.size() == 0){
        return true;
      }
      else{
        return false;
      }
  }

  void SetInt::insert(const int& val){
    if (exists(val) != true){
      list_.push_back(val);
    }
  }

  void SetInt::remove(const int& val){
    if (exists(val) == true){
      list_.remove(val);
    }
  }

  bool SetInt::exists(const int& val) const{
    for (int i = 0; i < list_.size(); i++){
      int value = list_.get(i);
      if (value == val){
        return true;
      }
    }
    return false;
  }

  int const* SetInt::first(){
    increment = 0;
    if (empty() == false){
        ptr_f = &list_.get(0);
        ptr_n = ptr_f;
        return ptr_f;
    }
    ptr_f = NULL;
    return ptr_f;
  }

  int const* SetInt::next(){
      increment += 1;
      if (increment > size()){
        return NULL;
      }
      else {
        ptr_n = &list_.get(increment);
        return ptr_n;
      }
  }

SetInt SetInt::setUnion(const SetInt& other) const{
   SetInt l3;
   int size = this->size();
   for (int i = 0; i < size; i++){
     int value = this->list_.get(i);
     l3.insert(value);
   }
   int secsize = other.size();
   for (int i = 0; i < secsize; i++){
     int value = other.list_.get(i);
     l3.insert(value);
   }
   return l3;
}

  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
SetInt SetInt::setIntersection(const SetInt& other) const{
  SetInt l3;
  bool alreadyIn = false;
  int size = this->size();
  int secsize = other.size();
  for (int i = 0; i < size; i++){ 
    int value = this->list_.get(i); 
    for (int j = 0; j < secsize; j++){ 
        int com_val = other.list_.get(j); 
        if (com_val == value){
          int l3size = l3.size();
          if (l3size > 0){
            for (int k = 0; k < l3size; k++){
              int l3val = l3.list_.get(k);
              if (l3val == com_val){
                alreadyIn = true;
              }
            } 
            if (alreadyIn != true){
              l3.insert(value);
            }
          }
          else {
            l3.insert(value);
          }
        }
        alreadyIn = false;
    }
  }
  return l3;
}

SetInt SetInt::operator|(const SetInt& other) const{
   SetInt l3;
   int size = this->size();
   for (int i = 0; i < size; i++){
     int value = this->list_.get(i);
     l3.insert(value);
   }
   int secsize = other.size();
   for (int i = 0; i < secsize; i++){
     int value = other.list_.get(i);
     l3.insert(value);
   }
   return l3;
}

SetInt SetInt::operator&(const SetInt& other) const{
  SetInt l3;
  bool alreadyIn = false;
  int size = this->size();
  int secsize = other.size();
  for (int i = 0; i < size; i++){ 
    int value = this->list_.get(i); 
    for (int j = 0; j < secsize; j++){ 
        int com_val = other.list_.get(j); 
        if (com_val == value){
          int l3size = l3.size();
          if (l3size > 0){
            for (int k = 0; k < l3size; k++){
              int l3val = l3.list_.get(k);
              if (l3val == com_val){
                alreadyIn = true;
              }
            } 
            if (alreadyIn != true){
              l3.insert(value);
            }
          }
          else {
            l3.insert(value);
          }
        }
        alreadyIn = false;
    }
  }
  return l3;
}