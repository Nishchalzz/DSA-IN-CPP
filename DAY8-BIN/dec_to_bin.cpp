#include<iostream>
using namespace std;

void dtb(int n){
    int rem, sum=0;
    int pow=1;
    while(n>0){
        rem = n%2;
        sum += rem*pow;
        pow = pow*10;
        n = n/2;
    }

    cout<<sum;
}

int main(){
    int n;
    cout<<"Enter the binary_num: ";
    cin>>n;

    dtb(n);
    return 0;
}