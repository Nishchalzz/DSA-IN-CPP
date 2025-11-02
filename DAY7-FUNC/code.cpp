#include<iostream>
using namespace std;

int product(int a, int b=5){
    int product = a*b;
    return product;
}

bool isEven(int n){
    if(n%2==0)
        return true;
    else
        return false;
}

int main(){
    int p = product(2,5);
    cout<<"Product: "<<p<<endl;
    bool a = isEven(46);
    if(a)
        cout<<"Even";
    else    
        cout<<"odd";
    return 0;
}