#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number n: ";
    cin>>n;
    int fact=1;
    for(int i=n;i>0;i--){
        fact *= i;
    }
    cout<<"Fact: "<<fact;
    return 0;
}