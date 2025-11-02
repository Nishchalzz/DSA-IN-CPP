#include<iostream>
#include<stack>
using namespace std;

void PAB(stack<int> &stack, int value){
    if(stack.empty()){
        stack.push(value);
        return;
    }

    int temp=stack.top();
    stack.pop();
    
    PAB(stack, value);

    stack.push(temp);

}


int main(){

    stack<int> s;
    s.push(2);
    s.push(1);

    PAB(s, 3);

    while(!s.empty()){
        cout<<s.top()<<"  ";
        s.pop();
    }

    return 0;
}