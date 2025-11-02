#include<iostream>
using namespace std;

int main(){
    //inc and dec
    // int a = 10;
    // int *ptr = &a;
    // cout<<ptr<<endl;
    // cout<<--ptr<<endl;

    //pointer addn and subn of constatant
    // int arr[5]={3,2,4,1,2};
    // int *ptr = arr;
    // for(int i=0;i<5;i++){
    //     cout<<*(arr+i)<<endl;
    // }

    //pointer addn and subn of ponter
    //addn invalid
    // int a = 20;
    // int *ptr1 = &a;
    // int *ptr2 = ptr1 + 3;
    // cout<<ptr2-ptr1;

    //pointer comparision
    int arr[10]={1,2,3,4,5,6};
    int *ptr1 = arr;
    int *ptr2 = arr+3;
    cout<<(ptr1==arr)<<endl;
    cout<<(ptr1>ptr2);

    return 0;
}