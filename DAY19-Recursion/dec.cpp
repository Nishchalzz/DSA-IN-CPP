#include<iostream>
using namespace std;
 
// print numbers in decreasing order

void print(int n){
    if(n==0)
        return;
    cout<<n<<"  ";
    print(n-1);  //desc

    
    // print(n-1);
    // cout<<n<<"  ";   // asc
}

int main(){
    print(15);
    return 0;
}