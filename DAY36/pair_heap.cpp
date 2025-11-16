#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


struct ComparePair{
    bool operator () (const pair<string, int> &p1,const  pair<string, int> &p2) const {
        return p1.second > p2.second;
    }
};


int main(){

    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;  //default max heap on first element

    pq.push(make_pair("arun", 99));
    pq.push(make_pair("rohan", 80));
    pq.push(make_pair("sushant", 45));

    while(!pq.empty()){
        cout<<pq.top().first<<"  "<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}