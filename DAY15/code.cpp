#include<iostream>
using namespace std;

int funcInt(){
    int *ptr=new int;
    *ptr=9;
    cout<<*ptr;
    delete ptr;
}

int func(){
    int size;
    cin>>size;
    int *arr = new int[size];
    int x=1;

    for(int i=0;i<size;i++){
        arr[i]=x++;
        cout<<arr[i];
    }

    delete[] arr;
}

int* funcret(){
    int *ptr = new int;
    *ptr=8;
    cout<<"ptr="<<*ptr<<endl;
    return ptr;
    //should add delete
}

int main(){
    // funcInt();
    // int *x = funcret();
    // cout<<*x;
    return 0;
}