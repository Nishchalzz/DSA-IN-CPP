#include <climits>

int findKRotation(vector<int> &arr){
    int n = arr.size();
    int low = 0, high = n-1;
    int ans = INT_MAX, index = -1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[low]<=arr[mid]){
            ans = min(arr[low], ans);
            if(ans == arr[low])
                index = low;
            low = mid+1;
        }else{
            ans = min(ans, arr[mid]);
            if(ans == arr[mid])
                index = mid;
            high = mid - 1;
        }

    } 
    return index;
}