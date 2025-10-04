#include <iostream>
#include <string>
using namespace std ;

class president ;

class government {
  private:
   string code ="123";
   public :
   friend class president ;
};

class president {
    public :
    void getcode (government &gov) {
        cout<< "the secret code is " << gov.code <<endl;
    }

};

int main(){
    government gov ;
    president p;
    p.getcode(gov) ;
}