#include<iostream>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void SelectionSort(int *arr, int n){
    //ascending order
    for(int i=0;i<n-1;i++){
        int minIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIdx])
                minIdx = j;
        }
        swap(arr[minIdx],arr[i]);
    }

    //descendin order
    for(int i=0;i<n-1;i++){
        int maxIdx = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]>arr[maxIdx])
                maxIdx = j;
        }
        swap(arr[maxIdx],arr[i]);
    }


    printArray(arr,n);
}



int main(){
    int arr[6]={2,3,4,7,5,0};
    int n = sizeof(arr)/sizeof(int);
    SelectionSort(arr, n);
    
    return 0;
}