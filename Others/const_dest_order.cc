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


/*
Why constructors cannot be virtual:

Object type must be known at creation

When you do new Derived(), the compiler must know the exact type (Derived) at compile time so it can allocate the right size and lay out the vtable.

Virtual dispatch requires a vtable pointer, but that vtable isn’t set up until after the base constructor finishes.

So at the moment of construction, there’s no mechanism for polymorphic dispatch.

That’s why constructors can’t be virtual.

🔹 Why destructors can be virtual:

At destruction, dynamic type matters

If you delete an object through a base pointer (delete basePtr;), the compiler needs to destroy the most-derived object.

Virtual dispatch works here, because the vtable is still valid until the most-derived destructor starts.

So a virtual ~Base() ensures the derived destructor runs first, cleaning up derived resources, before base cleanup.


*/