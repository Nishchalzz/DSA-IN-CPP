#include<iostream>
using namespace std;

int getIthBit(int num, int pos){
    int bitMask = 1 << pos; 
    if(!(num & bitMask))
        return 0;
    else
        return 1;
}

int setIthBit(int num, int pos){
    int bitMask = 1 << pos;
    return (num | bitMask);
}

int clearIthBit(int num, int pos){
    int bitMask = ~(1<<pos);
    return (num & bitMask);
}

int main(){

    // cout<<getIthBit(6,2);
    // cout<<setIthBit(6,3);
    cout<<clearIthBit(6,1);

    return 0;
}