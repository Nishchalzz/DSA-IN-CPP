class Solution {
public:
    int helper(int n, vector<int> nums,vector<int> dp){
        if(n==0)
            return nums[0];
        if(n<0)
            return 0;

        if(dp[n]!=-1) return dp[n];

        int pick = nums[n] + helper(n-2,nums,dp);
        int notpick = helper(n-1,nums,dp);

        return dp[n] = max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        dp[0] = nums[0];

        for(int i=1;i<n;i++){
            int take = nums[i];

            if(i-2>=0)
                take += dp[i-2];
            
            int nottake = dp[i-1];
            dp[i] = max(take,nottake);
        }

        return dp[n-1];
    }
};