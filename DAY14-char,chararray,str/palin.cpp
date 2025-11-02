#include<iostream>
#include<cstring>
using namespace std;

bool isPalin(char word[], int n){
    int st=0,end=n-1;
    while(st<end){
        if(word[st++]!=word[end--])
            return false;
    }
    return true;
}

int main(){
    char word[50] = "apple";
    bool ip = isPalin(word, strlen(word));
    cout<<ip;

    return 0;
}