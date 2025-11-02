#include<iostream>
using namespace std;

int main(){
    int a=0,b=1,n;
    cout<<"Enter the number n:";
    cin>>n;
    int i=1;
    while(i<=n){
        cout<<a<<"  ";
        int temp =a;
        a=b;
        b=a+temp;
        i++;
    }

    return 0;
}