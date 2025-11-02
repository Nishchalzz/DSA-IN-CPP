#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3};
    int arr1[50] = {1,2,3};
    int arr2[50];
    cout<<sizeof(arr2)/sizeof(int);
    cout<<arr2[1]<<endl<<arr2[25];
    return 0;
}
 
