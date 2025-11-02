#include<iostream>
#include<stack>
using namespace std;

void PAB(stack<int> &s, int val){
    if(s.empty()){
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();
    PAB(s, val);

    s.push(temp);
}


void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    PAB(s, temp);
}


int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    reverse(s);
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}