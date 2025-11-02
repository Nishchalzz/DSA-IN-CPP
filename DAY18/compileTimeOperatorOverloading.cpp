#include<iostream>
#include<string>
using namespace std;

class Complex{
    int r,i;
public:
    Complex(int r, int i){
        this->r=r;
        this->i=i;
    }
    void show(){
        cout<<r<<" + "<<i<<"i"<<endl;
    }
    Complex operator - (Complex &c2){
        int real = this->r - c2.r;
        int img = this->i - c2.i;
        Complex c3(real, img);

        return c3;
    }

};

int main(){
    Complex c1(3,2);
    Complex c2(2,1);

    c1.show();
    c2.show();

    Complex c3 = c1-c2;
    c3.show();

    return 0;
}