#include<iostream>
#include<climits>
using namespace std;

int watertrap(int *heights, int n){
    int leftMax[20000],rightMax[20000];
    leftMax[0]=heights[0];
    rightMax[n-1]=heights[n-1];
    for(int i=1;i<n;i++){
        leftMax[i]=max(heights[i-1],leftMax[i-1]);
    }
    for(int i=n-2;i>=0;i--){
        rightMax[i]=max(rightMax[i+1], heights[i+1]);
    }
    int waterTrapped=0;
    for(int i=0;i<n;i++){
        int currTrap = min(rightMax[i], leftMax[i])-heights[i];
        if(currTrap>0){
            waterTrapped += currTrap;
        }
    }
    return waterTrapped;

}

int main(){
    int arr[7]={4,2,0,6,3,2,5};
    int n = sizeof(arr)/sizeof(int);

    int trappedWater = watertrap(arr, n);

    cout<<"Water Trapped: "<<trappedWater;

    return 0;
}