class Solution {
public:
    bool helper(int idx, int target,vector<int>& nums,vector<vector<int>> dp){
        if(target == 0)
            return true;
        if(idx<0)
            return false;

        if(dp[idx][target] != -1)
            if(dp[idx][target]==1)
                return true;
            else 
                return false;


        bool pick = false;
        if(target-nums[idx]>=0)
            pick = helper(idx-1,target-nums[idx],nums,dp);
        bool notpick = helper(idx-1,target,nums,dp);

        if(pick || notpick)
            dp[idx][target] = 1;
        else 
            dp[idx][target] = 0;

        return pick || notpick;
    }

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