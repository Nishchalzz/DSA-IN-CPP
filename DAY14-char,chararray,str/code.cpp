#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    // char word[] = "code123";
    // cout<<strlen(word)<<endl;

    // char sentence[50];
    // cin.getline(sentence, 30, '*');

    // cout<<sentence<<endl;
    // cout<<strlen(sentence)<<endl;

    // char str1[10] = "hello";
    // char str2[10];
    // strcpy(str2,"world");
    // strcat(str2,str1);
    // cout<<str2;

    string str="hello i am hhu";
    // getline(cin,str,'*');
    // cout<<str;
    for(char ch: str){
        cout<<ch<<" ";
    }
    cout<<endl;

    return 0;
}