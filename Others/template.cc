// Learning Templates in C++ , Till now of what I understood is that the templates in c++ are for reusablitily and example can be shown below 
#include <iostream>
#include <string> 

// What if I have to write a print function in which I have to print pretty much every thing wether it be a int or a char ...
// typename and class can be used interchangebly .
template <typename T> 
void print(T value) {
    std :: cout<< value << std :: endl ;

}

// This means that this is an template that will be evaluated at the compile time .
// The template desent really exist until its called . If I make it like this 
/* 

template <typename T> 
void print(T value) {
    std :: cout<< vadfsdfsf << std :: endl ;

}

and dont call it then no error .
 */
int main (){
    print ("shrikar") ;
    // or 
    print<std ::string> ("shrikar") ;
     print (5) ;
      print (5.32) ;
    return 0;      
}