#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<string, vector<string>, greater<string>> pq;
    pq.push("apna");
    pq.push("cpp");
    pq.push("dance karenge");

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    return 0;
}
