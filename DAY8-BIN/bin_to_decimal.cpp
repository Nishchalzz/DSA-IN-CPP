#include<iostream>
using namespace std;


void btd(int num){
    int rem, sum=0;
    int pow =1;
    while(num>0){
        rem = num%10;
        sum += rem*pow;
        pow = pow*2;
        num /= 10;
    }
    cout<<sum;

}

int main(){
    int n;
    cout<<"Enter the binary_num: ";
    cin>>n;

    btd(n);

    return 0;
}