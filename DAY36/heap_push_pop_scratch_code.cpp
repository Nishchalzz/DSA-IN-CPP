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

    void heapify(int i){

        if(i>=vec.size())
            return;

        int l = 2*i + 1;
        int r = 2*i + 2;

        int maxidx = i;

        if(l<vec.size() && vec[l]>vec[maxidx]){
            maxidx = l;
        }

        if(r<vec.size() && vec[r]>vec[maxidx]){
            maxidx = r;
        }

        swap(vec[maxidx],vec[i]);

        if(maxidx != i){
            heapify(maxidx);
        }

    }

    void pop(){

        //swap first, last
        swap(vec[0], vec[vec.size()-1]);

        //remove the last
        vec.pop_back();

        //heapify maintaint the 
        heapify(0);


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
    h.pop();
    cout<<h.top()<<endl;



    return 0;
}