#include<iostream>
using namespace std;
 
// print numbers in decreasing order

int sumOfN(int n){
    if(n==1)
        return 1;

    return (n + sumOfN(n-1));
}

int main(){
    cout<<sumOfN(10);
    return 0;
}