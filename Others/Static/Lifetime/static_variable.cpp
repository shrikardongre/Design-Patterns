// Static Variables are allocated on Static memory with global variables.
// These are allocated before runtime and live throughout the lifetime of the code . 

#include <iostream>
using namespace std ;

void inc() {
    static int a = 5;
    a++;
    cout << a << endl;
}

int main() {
 inc();
 inc();
 return 0;
}

// Same variable is incremented everytime as it lives in the static memory and not in the stack . Same behaviour can be achieved with global variable.