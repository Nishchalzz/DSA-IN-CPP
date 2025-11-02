#include<iostream>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}


int main(){
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);


    //EXTRA SPACE
    // int copy[n];
    // for(int i=0;i<n;i++){
    //     copy[i]=arr[n-i-1];
    // }
    // for(int i=0;i<n;i++){
    //     arr[i]=copy[i];
    // }

    //NO EXTRA SPACE O(1) space compelxity
    int start = 0, end = n-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;end--;
    }
    printArr(arr,n);

    return 0;
}
 
