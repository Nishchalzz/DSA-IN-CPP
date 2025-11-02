#include<iostream>
using namespace std;
 
//O(logn)
// int pow(int x, int n){
//     if(n==0)
//         return 1;

//     return x*pow(x,n-1);
// }

int pow(int x, int n){
    if(n==0)
        return 1;

    int halfpow = pow(x,n/2);
    int squarepow = halfpow*halfpow;

    if(n%2!=0)
        return x*squarepow;
    return squarepow;
}

int main(){
    cout<<pow(2,9);
    return 0;
}