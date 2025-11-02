#include<iostream>
using namespace std;

int linearsearch(int *arr,int n, int key){
    for(int i=0;i<n;i++){
        if(key==arr[i])
            return i;
    }
    return -1;
}

int main(){
    int n,key,pos;
    cout<<"Enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter the key element to find: ";
    cin>>key;

    pos = linearsearch(arr, n, key);
    if(pos == -1)
        cout<<"ele not found"<<endl;
    else
        cout<<"Index is: "<<pos;
    return 0;
}