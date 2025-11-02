#include<iostream>
#include<climits>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void BubbleSort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
    printArray(arr,n);
}

void selectionSort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx])
                minIdx = j;
        }
        swap(arr[i],arr[minIdx]);
    }
    printArray(arr,n);
}


int main(){
    int arr[6]={2,3,4,7,5,0};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
    
    return 0;
}