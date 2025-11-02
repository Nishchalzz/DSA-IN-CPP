#include<iostream>
using namespace std;
 
// print numbers in decreasing order

bool isSorted(int *arr, int n,int i){
    if(i==n-1)
        return true;

    if(arr[i]>arr[i+1])
        return false;

    return isSorted(arr,n,i+1);
}

int main(){
    int arr[5] = {0,1,2,4,5};
    int i=0;
    cout<<isSorted(arr,5,i);
    return 0;
}