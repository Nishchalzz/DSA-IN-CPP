#include<iostream>
#include<climits>
using namespace std;

void printArray(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void countSort(int *arr, int n){
    int freq[10000] = {0};
    int minVal = INT_MAX, maxVal = INT_MIN;

    //STEP 1 assign freq arr
    for(int i = 0;i<n;i++){
        freq[arr[i]]++;
        minVal = min(minVal, arr[i]); //for range
        maxVal = max(maxVal, arr[i]);//for range
    }
     
    //STEP 2 store back to arr from freq
    int j=0;
    for(int i=minVal;i<=maxVal;i++){
        while(freq[i]>0){
            arr[j] = i;
            j++;
            freq[i]--;
        }
    }
    printArray(arr,n);
}



int main(){
    int arr[8]={1,4,1,3,2,4,3,7};
    int n = sizeof(arr)/sizeof(int);
    countSort(arr, n);
 
    return 0;
}