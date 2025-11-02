#include<iostream>
#include<string>
using namespace std;

int binSearch(int* arr, int start, int end, int target){
    if(start>end)
        return -1;
    int mid = start+(end-start)/2;
    if(arr[mid]==target)
        return mid;
    else{
        if(arr[mid]>target) 
            binSearch(arr,start, mid-1,target);
        else
            binSearch(arr,mid+1, end, target);
    }
}

int main(){
    int arr[7]={1, 2, 3, 4, 5, 6, 7};
    cout<<binSearch(arr,0,6,5);
    
    return 0;
}