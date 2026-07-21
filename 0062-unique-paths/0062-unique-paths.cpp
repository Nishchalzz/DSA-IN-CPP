class Solution {
public:
    int helper(int r, int c,vector<vector<int>>& dp){
        if(r==0 && c==0){
            return 1;
        }
        if(r<0 || c<0) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        //up and left
         return dp[r][c] = helper(r-1,c,dp) + helper(r,c-1,dp); 
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(m-1,n-1,dp);
    }
};