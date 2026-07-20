class Solution {
public:
    int helper(int n,vector<int>& dp){

       if(n==0 || n==1) return 1;

       if(dp[n]!=-1) return dp[n];

        int left = helper(n-1,dp);
        int right = helper(n-2,dp);

        return dp[n] = left + right;
    }

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;

        helper(n,dp);

        return dp[n];
    }
};