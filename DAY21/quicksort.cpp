#include<iostream>
using namespace std;

int partition(int arr[], int si, int ei){
    int i = si-1;
    int pivot = arr[ei];
    
    for(int j=si;j<ei;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[ei]);

    return i;
}

void quickSort(int arr[], int si, int ei){
    if(si>=ei){
        return;
    }

    int pivotIdx = partition(arr, si,ei);
    quickSort(arr, si, pivotIdx-1);
    quickSort(arr, pivotIdx+1, ei);
}
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}

int main(){
    int arr[6]={2,1,4,3,9,8};
    quickSort(arr,0,5);
    printArray(arr,6);
    return 0;
}