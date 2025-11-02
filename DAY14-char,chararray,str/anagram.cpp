#include<iostream>
#include<string>
using namespace std;

bool isAnagram(string str1, string str2){
    if(str1.length() != str2.length()){
        cout<<"not equal lenght so not a anagram";
        return false;
    }
    int count[26]={0};
    for(int i=0;i<str1.length();i++){
        count[str1[i]-'a']++;
    }

    for(int i=0;i<str2.length();i++){
        if(count[str2[i]-'a']==0){
            cout<<"not anagram";
            return false;
        }
        count[str2[i]-'a']--;
        
    }
    cout<<"It is anagram"<<endl;
    return true;

}


int main(){
    string str1="anagram", str2 = "nagaam";
    isAnagram(str1,str2);

    return 0;
}