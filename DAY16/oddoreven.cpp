#include<iostream>
using namespace std;

void oddOrEven(int num){
    if(num & 1)
        cout<<"Odd\n";
    else
        cout<<"even\n";
}

int main(){

    oddOrEven(5);
    oddOrEven(8);


    return 0;
}