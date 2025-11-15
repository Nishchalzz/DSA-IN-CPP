#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Heap{
    vector<int> vec;

public:
    void push(int val){
        //step 1: push to vec
        vec.push_back(val);

        //step 2: fix the cbt
        int childIdx = vec.size()-1;
        int parIdx = (childIdx - 1)/2;

        while(parIdx >= 0 && vec[childIdx] > vec[parIdx]){
            swap(vec[childIdx], vec[parIdx]);
            childIdx = parIdx;
            parIdx = (childIdx-1)/2;
        }

    }

    void pop(){

        //swap first, last

        //


    }

    int top(){
        return vec[0];
    }

    bool empty(){
        return vec.size() == 0;
    }



};

int main(){

    Heap h;
    h.push(10);
    h.push(2);
    h.push(20);

    cout<<h.top()<<endl;
    cout<<h.empty();



    return 0;
}