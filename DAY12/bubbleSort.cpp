#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n){
    //ascending order-little bit optimized for sorted array
    
    for(int i=0;i<n-1;i++){
        bool isSwap = false;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap=true;
            }
        }
        if(!isSwap){
            return;
        }
    }
    //descending order 
    // for(int i=0;i<n-1;i++){
    //     for(int j=0;j<n-i-1;j++){
    //         if(arr[j]<arr[j+1])  //just less than sign < change here we make smaller number move right
    //         swap(arr[j],arr[j+1]);
    //     }
    // }
}
void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    printArray(arr,n);
    return 0;
}