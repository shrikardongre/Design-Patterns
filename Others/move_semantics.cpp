// To understand why do we really need to move things rather than just copying .

#include <cctype>
#include <cstring>
#include <iostream>

class String {
public : 
String()=default;
String(const char* c) {
    std :: cout<<"created " << std :: endl;
    m_size= strlen(c);
    m_data=new char[m_size];
    memcpy(m_data,c,m_size);
}
String( const String& other){
  std::cout<<"copied"<<std::endl;
  m_size=other.m_size;
  m_data=new char[m_size];
   memcpy(m_data, other.m_data, m_size);
}

String (String&& other){
  std::cout<<"moved"<<std::endl;
  m_size=other.m_size;
  m_data=other.m_data;

  other.m_size=0;
  other.m_data=nullptr;
}

void Print(){
  for(int i=0;i<m_size;i++){

        if (std::isalpha(m_data[i])){
            std::cout<<m_data[i];
        }
      }
      std::cout<<std::endl;
}

~String(){
    std::cout<<"Destroyed"<<std::endl;
    delete[] m_data;
}

private:
char* m_data=nullptr ;
int m_size=0 ;
};
//----------------------------------------------------------------------------------
class Entity {
public:
  Entity (const String &name):m_name(name){
  }

  void printname(){
    m_name.Print();
  }

    Entity( String&& name):m_name(std::move(name)){
  }

private:
String m_name;

};

int main(){
    // Entity e("shrikar") ;
    Entity e(String("shrikar")) ;
    e.printname();
    std::cin.get();
  
}


// Notes : 

/*
String class manages a raw resource (memory allocated with new). 
When you manage resources like this, you need to tell C++ how to handle copying, moving, and destruction.

Temporary String is Created: C++ sees that the Entity constructor needs a String object, but you've provided a const char* ("shrikar")
This temporary object allocates memory on the heap for "shrikar" and its m_data pointer points to it.

Shallow Copy: The Entity constructor is called with this temporary String object. Inside the constructor, the line this->m_name = name; executes. 
Since you haven't defined your own copy logic (a copy constructor or a copy assignment operator), the compiler generates a default one.

Temporary String is Destroyed: The line Entity e("shrikar"); is now finished. The temporary String object created in step 1 is no longer needed, 
so it goes out of scope and its destructor ~String() is called.

The Dangling Pointer: The Entity object e still exists, but its m_name.m_data pointer is now dangling. 
It's pointing to memory that has been deallocated and is no longer valid.

Undefined Behavior: When you later call e.printname(), it tries to read from that invalid memory location. This is undefined behavior – it might crash, print garbage, or do nothing at all. 
In your case, it seems to crash or terminate before it can print anything.

By writing Entity e(String("shrikar"));, you are just being more explicit about creating the temporary object. 
The fundamental sequence of events that causes the bug remains exactly the same.

ERROR : 
Here an interesting error occured 

m_name is already a member of type String.
When you write this->m_name = name;, you’re trying to assign name to it.
But your String class does not have an assignment operator (operator=) defined.


  Entity( String&& name):m_name(name){
  }

  With the above code it actually just uses the copy constructor again so you need to explicitly cast it to a temporary.

    Entity( String&& name):m_name((String&&)name){
  }
  
  or 

      Entity( String&& name):m_name(std::move(name)){
  }

*/