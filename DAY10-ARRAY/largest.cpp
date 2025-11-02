#include<iostream>
using namespace std;

int main(){
    int arr[] = {13,21,33,12,44,13};
    int n = sizeof(arr)/sizeof(int);
    int max = arr[0];
    int min=arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<"Largest: "<<max<<endl;
    cout<<"Smallest: "<<min;


    return 0;
}