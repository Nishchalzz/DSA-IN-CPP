#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

bool isDup(string str){   
    stack<char> s;
    for(int i=0;i<str.size();i++){    //O(n)
        char ch = str[i];
        //opening
        if(ch!=')'){
            s.push(ch);
        }else{
            //closing
            if(s.top()=='('){
                return true;
            }
            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    cout<<isDup("(((a+b)*(c+d)))");

    return 0;
}