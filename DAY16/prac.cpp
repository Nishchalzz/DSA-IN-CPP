#include<iostream>
using namespace std;

void  updateI(int num, int i, int val){
    num = num & ~(1<<i);
    num = num | (val<<i);
    cout<<num;
}

void clearLastBits(int num, int i){
    // for(int j=0;j<i;j++){
    //     num = num & ~(1<<j);
    // }
    int bitMask = ~(0)<<i;
    num = num & bitMask;
    cout<<num;
}

int countSetBits(int num){
    int count = 0;
    while(num>0){
        int lastDigit = (num & 1);
        count += lastDigit;
        num = num>>1;
    }
    cout<<count<<endl;
    return count;
}

int main(){

    // updateI(7, 3, 1);
    // clearLastBits(15, 2);
    int n = countSetBits(11);
    return 0;
}