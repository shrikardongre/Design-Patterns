#include<iostream>
using namespace std ;

static int global_var;
       int global_var_;


int main(){
    static int local_var;
           int local_var_;

    cout<<&global_var<<" "<<&global_var_<<" "<<&local_var<<" "<<&local_var_<<endl;
    // only the last one is on the stack !!
}
