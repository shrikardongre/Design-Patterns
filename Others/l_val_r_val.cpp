#include <iostream> 

std :: string getname(std ::string &name){
    // This takes an lvalue reference as argument .
   std:: cout<<"lvalue function" << std::endl;
   std :: cout << name << std :: endl ;
   return name ;
}

std :: string getnameconst(const std ::string &name){
    // This takes an lvalue reference as argument .
   std:: cout<<"lvalue function" << std::endl;
   std :: cout << name << std :: endl ;
   return name ;
}

std :: string getname(std ::string &&name){
    // This takes an lvalue reference as argument .
   std:: cout<<"rvalue function" << std::endl;
   std :: cout << name << std :: endl ;
   return name ;
}

int main() {
 // simple l_value and r_value example 
 int i=10 ;
 // here i is the l_value and 10 that is a temporary variable is the r_value 
 // We can also do ,
 int a=i ;
 // here the roles are switched .
 std ::string first_name="Shrikar" ;
 std::string last_name="Dongre";
 std::string full_name= first_name+last_name ;

 // the below code will not throw any error as this is lvalue and can be passed by reference .
 getname(full_name);
 // below code will throw error as clearly the first_name+last_name  does not have any storage space so cannot be passed as reference.
 // but now it takes the other definition of the getname function that basically expects the rvalue as the argument .
 getname(first_name+last_name) ;

 // but this refuses to thorw error as it expects a rvlaue or a const ;
 getnameconst(first_name+last_name) ;

  /** 
  That function works because a const lvalue reference (const std::string&) can bind to temporary objects (rvalues), 
  but a non-const lvalue reference (std::string&) cannot.

  In C++, you're not allowed to pass a temporary object to a function that might try to change it. \
  The expression first_name+last_name creates a temporary std::string that has no name and will be destroyed right after the line executes.
  **/


}