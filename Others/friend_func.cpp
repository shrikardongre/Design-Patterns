//In C++, a friend function or a friend class is a way to grant an external function or another class special access to the private and protected members of a class.

#include <iostream>
#include <bits/stdc++.h>
using namespace std ;


class Human {
private:
    string name ;
    string secret;

public:
    Human(string name, string secret) : name(name) , secret(secret) {
    }
    
    friend void revealsecret(Human person) ;
    
};

void revealsecret(Human person){
    cout<<person.name<<" " << person.secret<<endl;
}

int main(){
    Human h ("Shrikar","He likes C++") ;
    revealsecret(h);
}
