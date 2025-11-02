#include<iostream>
using namespace std;

void printSubArray(int *arr, int n){
    for(int start=0;start<n;start++){
        for(int end=start;end<n;end++){
            for(int k=start;k<=end;k++){
                cout<<arr[k];
            }
            cout<<", ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(int);
    printSubArray(arr,n);
    return 0;

}