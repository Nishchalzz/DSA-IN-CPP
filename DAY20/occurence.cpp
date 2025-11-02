#include<iostream>
#include<string>
using namespace std;

void occur(int *arr, int n, int i, int target){
    //base case
    if(i==n)
        return;
    if(arr[i]==target)
        cout<<i<<"\t";
    occur(arr,n, i+1, target);
}

int main(){
    int arr[6] = {1,2,3,2,4,2};
    occur(arr,6,0,2);
    
    return 0;
}