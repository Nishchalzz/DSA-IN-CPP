#include<iostream>
#include<stack>
#include<string>
using namespace std;

string reverseString(string str){
    string ans="";
    stack<char> s;
    
    for(int i=0;i<str.size();i++){
        s.push(str[i]);
    }
    while(!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}


int main(){

   cout<<reverseString("hello");

    return 0;
}