#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

void heapify(int i, vector<int> &arr, int n){

    if(i >= n )
        return;

    
    int l = 2*i+1;
    int r = 2*i+2;

    int maxidx = i;

    if(l<n && arr[l] > arr[maxidx]){
        maxidx = l;
    }

    if(r<n && arr[r] > arr[maxidx]){
        maxidx = r;
    }

    swap(arr[maxidx], arr[i]);

    if(maxidx != i){
        heapify(maxidx, arr, n);
    }


}

void heapSort(vector<int> &arr){
    int n = arr.size();

    //step 1: building maxheap
    for(int i=(n/2)-1;i>=0;i--){    //o(nlogn)
        heapify(i, arr, n);
    }

    //step 2:taking elements to the correct pos
    for(int i=n-1;i>=0;i--){                //o(nlogn)
        swap(arr[0], arr[i]);
        heapify(0, arr, i);
    }

}

int main(){

    vector<int> arr = {1,4,2,5,3};
    heapSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<"\t";
    }


    return 0;
}