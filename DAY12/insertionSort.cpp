#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void insertionSort(int *arr, int n){
    // for(int i=1;i<n;i++){
    //     for(int j=i-1;j>=0;j--){
    //         if(arr[i]<arr[j]){
    //             swap(arr[i],arr[j]);
    //             i--;
    //         }
    //     }
    // }
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]>curr){  //for desc order, arr[prev]<curr
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        // arr[prev+1]=curr;
    }
    printArray(arr,n);

}



int main(){
    int arr[10]={7,6,9,0,8,5,4,1,3,2};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
 
    return 0;
}