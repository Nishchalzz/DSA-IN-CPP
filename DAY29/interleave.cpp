#include<iostream>
#include<queue>
using namespace std;

void interleve(queue<int> &org){
    queue<int> first;
    int n=org.size();
    for(int i=0;i<n/2;i++){
        first.push(org.front());
        org.pop();
    }
    //first , org ->  org
    while(!first.empty()){
        org.push(first.front());
        first.pop();
        org.push(org.front());
        org.pop();
    }
    while(!org.empty()){
        cout<<org.front()<<"   ";
        org.pop();
    }
    
}

int main(){
    queue<int> q;
    for(int i=1;i<11;i++){
        q.push(i);
    }
    interleve(q);
    return 0;
}