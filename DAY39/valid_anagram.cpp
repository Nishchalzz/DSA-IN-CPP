#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

bool validAnagram(string s1, string s2){
    if(s1.size() != s2.size()){
        return false;
    }

    unordered_map<char, int> m;



    for(int i=0;i<s1.size();i++){
        if(m.count(s1[i])){
            m[s1[i]]++;
        }else{
            m[s1[i]] = 1;
        }
    }

    for(int i=0;i<s2.size();i++){
        if(m.count(s2[i])){
            m[s2[i]]--;
            if(m[s2[i]]==0)
                m.erase(s2[i]);
        }else{
            return false;
        }
    }

    return m.size()==0;
 
}

int main(){

    cout<<validAnagram("casrer","race");

    return 0;
}