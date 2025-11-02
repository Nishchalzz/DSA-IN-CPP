#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value n: ";
    cin>>n;
   int revdig=0,rem;
//     while(n>0){
//         rem = n%10;
//         cout<<rem<<" ";
//         sum+=rem;
//         n=n/10;
//     }
//     cout<<sum;

    while(n>0){
        rem = n%10;
        revdig=revdig*10+rem;
        n/=10;
    }
    cout<<revdig;

    return 0;
}

