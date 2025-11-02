#include<iostream>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void arrcomp(int *arr,int n, int i){
    if(i==n){
        printArr(arr,n);
        return;
    }

    arr[i]=i+1;
    arrcomp(arr, 5, i+1);
    arr[i] -=2;

}

int main(){
     int arr[5]={0};
    arrcomp(arr,5,0);
    cout<<endl;
    printArr(arr, 5);
    return 0;
}