#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[6]={1,4,3,2,6,5};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,arr+n); //asc //0 to n-1
    sort(arr,arr+n,greater<int>()); //desc                 //O(nlogn)
    printArray(arr, n);
 
    return 0;
}