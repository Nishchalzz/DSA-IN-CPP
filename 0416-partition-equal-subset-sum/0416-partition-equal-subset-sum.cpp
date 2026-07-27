class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        if(total%2!=0) return false;
        vector<bool> dp(total/2+1,false),curr(total/2+1,false);

        dp[0]=true;
        curr[0] = true;
        if(nums[0]<total/2+1)
            dp[nums[0]] = true;

        for(int i=1;i<n;i++){
            for(int target = 1;target<total/2+1;target++){
                bool pick = false;
                if(target-nums[i]>=0)
                    pick = dp[target-nums[i]];
                bool notpick = dp[target];

                curr[target] = pick || notpick;
            }
            dp = curr;
        }
        return curr[total/2];
    }
};