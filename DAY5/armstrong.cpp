#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the number n: ";
    cin>>n;
    int rem,sum=0,num1=n;

    while(n>0){
        rem = n%10;
        sum += rem*rem*rem;
        n /= 10; 
    }
    // cout<<sum;
    if(num1==sum)
        cout<<"It is armstrong";
    else
        cout<<"It is not armstrong";
}