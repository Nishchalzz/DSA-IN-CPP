#include<iostream>
#include<cstring>
using namespace std;

void reverse(char word[], int n){
    // for(int i=0;i<n/2;i++){
    //     swap(word[i],word[n-i-1]);
    // }
    int st =0,end=n-1;
    while(st<end){
        swap(word[st++],word[end--]);
    }
}

int main(){
    char word[] = "apple";
    reverse(word, strlen(word));
    cout<<word;

    return 0;
}