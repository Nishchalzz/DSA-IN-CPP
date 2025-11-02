#include<iostream>
using namespace std;

//pointer pass by reference
void changeA(int *a){
    *a=20;
    cout<<*a<<" Inside func "<<endl;
}


//reference pass by reference
void changeA(int &a){
    a=20;
    cout<<a<<" Inside func "<<endl;
}

int main(){
    int a = 10;
    changeA(a);
    cout<<a<<" Inside main";
    // int a = 5;
    // int &b = a;
    // b=35;
    // cout<<a<<endl<<b;
    return 0;
}