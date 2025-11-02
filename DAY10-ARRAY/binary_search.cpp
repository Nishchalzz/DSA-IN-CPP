#include<iostream>
using namespace std;

int binsearch(int *arr, int n, int key){
    int mid,start=0,end=n-1;
    while(start<=end){
        mid = (start+end)/2;
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]<key)
            start = mid+1;
        else
            end = mid-1;
    }
    return -1;
}

int main(){

    int arr[] = {1,3,5,7,9};
    int n = sizeof(arr)/sizeof(int);
    int index = binsearch(arr, n, 10);
    cout<<"Index: "<<index;

    return 0;
}