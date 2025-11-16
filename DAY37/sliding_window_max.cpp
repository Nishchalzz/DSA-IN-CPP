#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Ele{
public: 
    int val;
    int idx;

    Ele(int val, int idx){
        this->val = val;
        this->idx = idx;
    }

    bool operator < (const Ele &obj) const {
        return this->val < obj.val;
    }
};



void slidingWindow(vector<int> arr, int k){
    priority_queue<Ele> pq;

    for(int i=0;i<k;i++){
        pq.push(Ele(arr[i],i));
    }

    cout<<"IDX: "<<pq.top().val<<endl;

    for(int i=k;i<arr.size();i++){
        

        while(pq.top().idx <= (i-k)){
            pq.pop();
        }

        pq.push(Ele(arr[i], i));

        cout<<"IDX: "<<pq.top().val<<endl;

    }
    


}

int main(){

    vector<int> arr = {1,3,-1,-3,5,3,6,7};
    int k = 3;

    slidingWindow(arr, k);

    return 0;
}