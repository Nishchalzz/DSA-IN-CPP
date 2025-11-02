#include<iostream>
using namespace std;

void nextchar(char ch){
    if(ch=='z')
        cout<<'a';
    else if(ch == 'Z')
            cout<<'A';
        else 
            cout<<++ch;

}


int main(){
    char ch;
    cout<<"Enter ch: ";
    cin>>ch;
    nextchar(ch);
    return 0;
}