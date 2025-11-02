#include<iostream>
using namespace std;

void isPalin(int n){
    int n1=n, rem, sum=0;
    while(n>0){
        rem = n%10;
        sum = sum*10 + rem;
        n/=10;
    }
    if(n1==sum)
        cout<<"Yes palindrome:";
    else
        cout<<"Its not palindrome: ";

}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    isPalin(n);
    return 0;
}