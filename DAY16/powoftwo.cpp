#include<iostream>
using namespace std;

bool powOfTwo(int num){
    if(!(num & (num-1))){
        return true;
    }else
    return false;
}

int main(){

    cout<<powOfTwo(7);

    return 0;
}