#include<iostream>
using namespace std;

int main(){

    int year;
    cin>>year;
    if(year%100==0){
        if(year%400==0){
            cout<<"leap year";
        }else
            cout<<"not a leap year";
    }else if(year%4==0)
        cout<<"it is  a leap year";
    else
        cout<<"it is not a leap year";

    return 0;
}