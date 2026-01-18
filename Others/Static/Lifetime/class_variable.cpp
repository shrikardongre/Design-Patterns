#include<iostream> 
using namespace std;

class Thing{
    private:
    // Ideally the static variable is kept private .
    static int num;
    public:
    //static int num; Here public declaration was tested .
    Thing(){num++;}
    ~Thing(){num--;}
    // To incorporate the private static variable we need to implement the getter and setter methods.
    // Without adding static to the functions below these methods belong to some specific objects and are not simple class methods.
    // So to access them you will need to create an object first.
    static int get_num(){return num;}
    void set_num(int a){num=a;}
};

int Thing::num=0;

int main(){
    // Thing thing1 ;
    // Thing thing2 ;

    cout<<Thing::get_num()<<endl;

   

}