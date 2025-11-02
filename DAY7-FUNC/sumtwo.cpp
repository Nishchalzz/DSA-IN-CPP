#include<iostream>
using namespace std;

void sum(int n){
    int n1=n, rem, sum=0;
    while(n>0){
        rem = n%10;
        sum = sum+ rem;
        n/=10;
    }
    cout<<sum;

}

void largest(int a, int b, int c){
    if(a>=c && a>=b)
        cout<<a;
    else if(c>=b)
            cout<<c;
        else
            cout<<b;
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    sum(n);

    largest(11,12,23);
    return 0;
}