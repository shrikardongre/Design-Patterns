// Templates are not only bound to functions and hence entire classes can be passed as templates ,
// What if I want a array class to be created on a stack .

#include<iostream>
#include<string> 

// this code wil lget compiled based on the usage required .
template <typename t , int N>

class Array {
private :
t m_Array[N] ;
public :
int GetSize() const {return N;}

t& operator[](int index) {
   return m_Array[index] ;
}

};

int main(){
    Array<int ,5> arr ;
    arr[3]=5 ;
    std :: cout<<arr[3] << std :: endl ;
    std :: cout<<arr.GetSize()<<std :: endl;

}

