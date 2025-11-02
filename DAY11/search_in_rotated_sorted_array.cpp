#include<iostream>
#include<climits>
using namespace std;

int searchtrotated(int *arr, int target, int n){
    int low = 0, high = n-1,mid;
    while(low<=high){
        mid = (low+high)/2;

        if(arr[mid]==target)
            return mid;

        if(arr[low]<=arr[mid]){
            if(arr[low]<=target && target<arr[mid]){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else{
            if(arr[mid]<target && arr[high]>=target){
                low=mid+1;
            }else{
                high = mid-1;
            }
        }
    
    }


    return -1;
}

int main(){
    int arr[2]={3,1};
    int n =sizeof(arr)/sizeof(int);

    int res = searchtrotated(arr, 1,n);
    if(res == -1){
        cout<<"Not found";
    }else
        cout<<"Index: "<<res;

    return 0;
}