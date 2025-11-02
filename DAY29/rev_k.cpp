#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void rev(queue<int> &q, int k){
    stack<int> s;
    int n = q.size();
    int run = n-k;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<run;i++){
        q.push(q.front());
        q.pop();
    }
}

int main(){
    queue<int> q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    int k=3;
    rev(q, k);

    while(!q.empty()){
        cout<<q.front();
        q.pop();
    }

    return 0;
}