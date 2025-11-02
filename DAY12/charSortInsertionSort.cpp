#include<iostream>
#include<climits>

using namespace std;

void printArray(char *arr, int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void charSort(char *arr, int n){
    for(int i=1;i<n;i++){
        int curr = arr[i];
        int prev = i-1;
        while(prev>=0 && arr[prev]<curr){
            swap(arr[prev],arr[prev+1]);
            prev--;
        }
        arr[prev+1]=curr;
    }
    printArray(arr, n);
}

int main(){
    char arr[5]={'a','d','e', 'b','c'};
    charSort(arr, 5);
    return 0;
}