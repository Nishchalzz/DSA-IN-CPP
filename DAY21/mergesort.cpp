#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int si, int ei,int mid){
    int i = si;
    int j = mid+1;
    vector<int> temp;

    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i++]);
        }else{
            temp.push_back(arr[j++]);
        }
    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }
    while(j<=ei){
        temp.push_back(arr[j++]);
    }

    for(int idx=si, k=0;idx<=ei;idx++){
        arr[idx]=temp[k++];
    }
}

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}



void mergesort(int arr[], int si, int ei, int n){
    if(si>=ei){
        return;
    }

    int mid = si + (ei-si)/2;

    mergesort(arr,si,mid,n);
    mergesort(arr,mid+1,ei,n);

    merge(arr,si,ei, mid);
}

int main(){
    int arr[6]={5,2,3,6,1,0};
    mergesort(arr, 0,5, 6);
    printArray(arr,6);
    return 0;
}