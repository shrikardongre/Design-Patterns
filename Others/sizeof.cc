#include <iostream>
#include <typeinfo>

void f(int* a) {
 std::cout<<sizeof(a)<<std::endl; // size of pointer (8 bytes)
}

int main() {
    // Write C++ code here
    std::cout << "Try programiz.pro" << std::endl;
    int a[5] = {1,2,3,4,5};
    std::cout<<*a<<" "<<sizeof(a)<<" "<<std::endl;
    f(a);
    
    return 0;
}
