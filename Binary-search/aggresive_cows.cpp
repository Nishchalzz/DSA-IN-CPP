bool canweplace(vector<int> arr, int dist, int cows){
    int cntcows=1, last = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]-last>=dist){
            cntcows++;
            last = arr[i];
        }
        if(cntcows==cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k)
{   int n = arr.size();
    sort(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int mini = *min_element(arr.begin(), arr.end());
    int low = 0, high = maxi-mini;
    int ans;
    while(low<=high){
        int mid = (low+high)/2;
        
        if(canweplace(arr, mid, k)){
            low=mid+1;   
        }else
            high = mid-1;
        
    }
    return high;

}