#include<iostream>
using namespace std;

int fact(int n){
    int fact = 1;
    for(int i=1;i<=n;i++){
        fact *= i;
    }
    return fact;
}

int main(){
    int n, r;
    float bc;
    cout<<"Enter n and r: ";
    cin>>n>>r;
    bc = (fact(n))/(fact(n-r)*fact(r));
    cout<<bc;

    return 0;
}