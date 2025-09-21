// Just a simple move constructor test
#include <cstddef>
#include <iostream>

class Myclass{
  private : 
    int* m_data = nullptr;
    size_t m_size = 0;

  public :
  // default constructor 
  Myclass(size_t size){
    std::cout << "CONSTRUCTOR: Allocating " << size << " integers." << std::endl;
    m_size=size;
    m_data=new int [size] ;
  }
  // copy constructor 
  Myclass(Myclass& object){
    std::cout<<"This is the copy constructor that will deep copy the data " << std :: endl ;\
    m_size= object.m_size;
    m_data=new int [m_size]; 
    std::copy(object .m_data, object .m_data + m_size, m_data); 
  }

  // Move constructor 
  Myclass(Myclass&& object) noexcept {
    std::cout << "MOVE CONSTRUCTOR: Stealing resources." << std::endl;
     m_data = object.m_data;
     m_size = object.m_size;
    
    // invlidating the source object 
    object.m_data = nullptr;
    object.m_size = 0;

  }

  ~Myclass() {
    if (m_data != nullptr) {
        std::cout << "DESTRUCTOR: Freeing memory." << std::endl;
        delete[] m_data;
    }
}
};

int main (){
    Myclass obj (100) ;
    Myclass copy (obj) ;
    Myclass moved(std::move(obj));
}