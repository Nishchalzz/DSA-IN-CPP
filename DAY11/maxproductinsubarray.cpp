#include<iostream>
#include<climits>
using namespace std;

void  maxsubarrayproduct(int *arr, int n){
        int ans = INT_MIN;
        int pre=1,suf=1;
        for(int i=0;i<n;i++){
            if(pre==0) pre = 1;
            if(suf==0) suf = 1;

            pre = pre*arr[i];
            suf = suf*arr[n-i-1];
            ans = max(ans,max(pre,suf));
        }
        cout<<ans;
}


int main(){
    int arr[7]={2,3,-9,0,-3,-2,4};
    int n = sizeof(arr)/sizeof(int);

    maxsubarrayproduct(arr, n);

    return 0;
}