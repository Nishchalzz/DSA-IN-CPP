//Count how many times lowercase vowels occurred in a String entered by the user

#include<iostream>
#include<string>
using namespace std;

void countVowel(string str){
    int count=0;
    for(char ch:str){
        if(ch=='a' || ch =='e' || ch =='i' || ch == 'o' || ch == 'u'){
            count++;
        }
    }
    cout<<"lowercase vowels occurred in a String: "<<count;
}

int main(){
    string str;
    cout<<"Enter the str: ";
    getline(cin,str);
    countVowel(str);

    return 0;
}