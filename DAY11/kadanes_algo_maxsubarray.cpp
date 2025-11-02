#include<iostream>
#include<climits>
using namespace std;

void maxsubarray(int *arr, int n){
    int currsum = 0;
    int maxsum = INT_MIN;
    for(int i=0;i<n;i++){
        currsum += arr[i];
        maxsum = max(currsum, maxsum);
        if(currsum<0)
            currsum = 0; 
    }

    cout<<"Max sub array sum: "<<maxsum;
}

int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    maxsubarray(arr, n);

    return 0;
}