  SetInt::SetInt(){}

  SetInt::~SetInt(){} //check llistint.cpp

  int SetInt::size() const{
     return list_.size();
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
    for (int i = 0; i < list.size(); i++){
      int value = list_.get(i);
      if (value == val){
        return true;
      }
    }
    return false;
  }

  int const* SetInt::first(){
    //creates a pointer to first item

  }

  int const* SetInt::next(){
    //moves the pointer created above to next item 
    //(or is it second pointer that moves?)
  }

  /**
   * Returns another (new) set that contains
   * the union of this set and "other"
   */
  SetInt setUnion(const SetInt& other) const;

  /**
   * Returns another (new) set that contains
   * the intersection of this set and "other"
   */
  SetInt setIntersection(const SetInt& other) const;

  SetInt operator|(const SetInt& other) const;

  SetInt operator&(const SetInt& other) const;


