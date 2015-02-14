#include "llistint.h"
#include <cstdlib>

LListInt::LListInt()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListInt::~LListInt()
{
  clear();
}

bool LListInt::empty() const
{
  return size_ == 0;
}

int LListInt::size() const
{
  return size_;
}

/**
 * Complete the following function
 */
void LListInt::insert(int loc, const double& val)
{
  if (size() == 0){
    Item* temp = new Item;
    temp->val = val;
    temp-> prev = NULL;
    temp-> next = NULL;
    
    head_ = temp;
    tail_ = temp;
    size_ += 1;
  }
  else if (loc < size()) {
    Item* temp = new Item;
    temp->val = val;
    temp->next = getNodeAt(loc);
    temp->prev = getNodeAt(loc-1);

    Item* after = getNodeAt(loc);
    Item* before = getNodeAt(loc-1);
    after-> prev = temp;
    before-> next = temp;
    size_ += 1;
  }
  else if (loc == size()){
    Item* temp = new Item;
    temp-> val = val;
    temp->next = NULL;
    temp->prev = getNodeAt(loc-1);
    Item* before = getNodeAt(loc-1);
    before->next = temp;
    size_ += 1;
    tail_ = temp;
  }
}

/**
 * Complete the following function
 */
void LListInt::remove(int loc)
{
  Item* rm = getNodeAt(loc);
  if (rm->prev == NULL){
    if (rm->next == NULL){
      delete rm;
      size_ = 0;
    }
    else {
      Item* nhead = getNodeAt(loc+1);
      nhead->prev = NULL;
      head_ = nhead;
      delete rm;
      size_ = size_ -1;
    }
  }
  else if (rm->next == NULL){
    Item* ntail = getNodeAt(loc-1);
    ntail->next = NULL;
    tail_ = ntail;
    delete rm;
    size_ = size_ - 1;
  }
  else{
    Item* before = getNodeAt(loc-1);
    Item* after = getNodeAt(loc + 1);
    before -> next = rm -> next;
    after -> prev = rm -> prev;
    delete rm;
    size_ = size_ - 1;
  }
}

void LListInt::set(int loc, const double& val)
{
  Item *temp = getNodeAt(loc);
  temp->val = val;
}

int& LListInt::get(int loc)
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

int const & LListInt::get(int loc) const
{
  Item *temp = getNodeAt(loc);
  return temp->val;
}

void LListInt::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}


LListInt::Item* LListInt::getNodeAt(int loc) const
{
  Item *temp = head_;
  if(loc >= 0 && loc < size_){
    while(temp != NULL && loc > 0){
      temp = temp->next;
      loc--;
    }
    return temp;
  }
  else {
    //throw std::invalid_argument("bad location");
    return NULL;
  }
}


  /**
   * Adds an item to the back of the list in O(1) time
   */
void LListInt::push_back(const int& val){
    Item* temp = new Item;
    if (this->size() == 0){
      head_ = temp;
      tail_ = temp;
      temp-> val = val;
      temp-> prev = NULL;
      temp-> next = NULL;
      size_ += 1;
    }
    else{
      temp-> val = val;
      temp->next = NULL;
      tail_->next = temp;
      temp->prev = tail_;
      size_ += 1;
      tail_ = temp;
    }
}

  /**
   * Copy constructor
   */
LListInt::LListInt(const LListInt& other){
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;

    for(int i = 0; i < other.size(); i++){
      int value = other.get(i);
      this->push_back(value);
    }
}

  /**
   * Assignment operator
   */
LListInt& LListInt::operator=(const LListInt& other){
  if (this == &other){
    return *this;
  }

  this->clear();

  for(int i = 0; i < other.size(); i++){
     int value = other.get(i);
     this->push_back(value);
  }
  return *this;  
}