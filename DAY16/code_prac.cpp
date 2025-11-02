#include<iostream>
using namespace std;

// void itojclear(int num, int i, int j){    
//     for(int k=i;k<=j;k++){
//         num = num & ~(1<<k);
//     }
//     cout<<num;
// }

void itojclear(int num, int i, int j){
    int a = ~(0) << (j+1);
    int b = (1<<i)-1;

    int mask = a | b;
    
    num = num & mask;

    cout<<num;
}

int main(){

    itojclear(15,1,3);

    return 0;
}