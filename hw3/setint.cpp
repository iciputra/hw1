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
    ptr_f = NULL;
    ptr_n = NULL;
    increment = 0;
    if (empty() == false){
      ptr_f = list_.get(0);
      ptr_n = list_.get(0);
    }
    return ptr_f;
  }

  int const* SetInt::next(){
    int i = increment + 1;
    if (i < size()){
      ptr_n = list_get(i);
      return ptr_n;
    }
    else {
      ptr_n = NULL;
      return ptr_n;
    }
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


