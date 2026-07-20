class Solution {
public:
    int helper(int n,vector<int>& dp){
        //memoization
       if(n==0 || n==1) return 1;

       if(dp[n]!=-1) return dp[n];

        int left = helper(n-1,dp);
        int right = helper(n-2,dp);

        return dp[n] = left + right;
    }

    int climbStairs(int n) {
        
        if(n<=1) return 1;
        int prev = 1; int prev2 = 1;
        //tabulation
        for(int i=2;i<=n;i++){
           int curr = prev+prev2;
           prev2 = prev;
           prev = curr;     
        }

        // helper(n,dp);

        return prev;
    }
};