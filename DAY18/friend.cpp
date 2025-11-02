#include<iostream>
#include<string>
using namespace std;

class A{
    string secret="secret key 123dwe211";
    friend class B;
    friend void revealKey(A &obj);
};

class B{
public:
    void show(A &obj){
        cout<<obj.secret<<endl;
    }
};

void revealKey(A &obj){
    cout<<obj.secret<<endl;
}

int main(){
    A a;
    B b;
    // b.show(a);
    revealKey(a);

    return 0;
}