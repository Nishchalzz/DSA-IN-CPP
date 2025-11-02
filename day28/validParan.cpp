#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

bool isValid(string str){
    stack<char> s;
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        //open
        if(ch=='(' || ch =='[' || ch == '{'){
            s.push(ch);
        }else{
            //close
            if(s.empty())
                return false;
            //match
            char top = s.top();
            if((top == '(' && ch == ')') ||
        (top == '[' && ch == ']') ||
    (top == '{' && ch == '}')){
                s.pop();
            }else
                return false;  
        }
    }
    return s.empty();

}

int main(){
    cout<<isValid("([{}())");

    return 0;
}