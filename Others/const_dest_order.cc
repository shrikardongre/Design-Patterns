// A simple test to check the order of constructors and destructors being called .
#include <cstddef>
#include<iostream>

class Base {
  public:
   Base(){
     std::cout<<"Base class constructor" << std::endl;
  }

  virtual ~Base(){
    std::cout<<"Base class destructor" << std:: endl; 
  }

};

class Derived : public Base {
public :

Derived(size_t size){
  this->size=size ;
  arr=new int [size];
  std :: cout << "This is the Derived class constructor" << std :: endl;
}

~Derived(){
  delete [] arr ;
  std :: cout << "This is the Derived class destructor" << std :: endl;
}

 private:
 int* arr ;
 size_t size ;
};

int main (){
    Base* ptr = new Derived(5);  // base pointer, derived object
    delete ptr;                  // delete through base pointer
    return 0;
}

// output of this program is (Here the base class destructor is virtual so the derived class dest. will be called first)
/*
Base class constructor
This is the Derived class constructor
This is the Derived class destructor
Base class destructor
*/