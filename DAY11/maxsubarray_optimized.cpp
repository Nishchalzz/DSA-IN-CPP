#include<iostream>
#include<climits>
using namespace std;

void maxsubarray(int *arr, int n){
    int maxsum=INT_MIN;
    for(int start=0;start<n;start++){ //2
        int sum = 0;
        for(int end = start;end<n;end++){ //2,3,4
            sum +=arr[end];
            cout<<sum<<", ";
            maxsum=max(sum,maxsum);
        }
        cout<<endl;
    }

    cout<<"Max sub array sum: "<<maxsum;
}

int main(){
    int arr[6]={2,-3,6,-5,4,2};
    int n = sizeof(arr)/sizeof(int);

    maxsubarray(arr, n);

    return 0;
}