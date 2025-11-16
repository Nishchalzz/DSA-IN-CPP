#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct CompareRope{
    bool operator() (int rope1, int rope2) const {
        return rope1 > rope2;
    }

};

int connectRopes(vector<int> ropes){
    priority_queue<int, vector<int>, CompareRope> pq(ropes.begin(), ropes.end());        //O(n)  !important


    int ans = 0;

    while(pq.size()>1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        ans += min1+min2;
        pq.push(min1+min2);
    }
    return ans;

}

int main(){
    vector<int> ropes = {4,3,2,6};

    cout<<connectRopes(ropes);

    return 0;
}