class Solution{
public:
    int longestSubarray(vector<int> &nums, int k){
        int i = 0;
        int j = 0; int n = nums.size();
        int sum = 0;
        int len = 0;
        sum+=nums[j];
        while(j<n){ 
            while(i<=j && sum>k){
                sum -=nums[i];
                i++;
            }
            if(sum == k){
                len = max(len, j-i+1);
            }
            j++;
            if(j<n) sum+=nums[j];

        }
        return len;
    }
};
