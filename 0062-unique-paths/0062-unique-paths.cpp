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
        dp[0][0] = 1;
        
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 && c==0) continue;
                dp[r][c] = 0;
                if(r-1>=0)
                    dp[r][c] = dp[r-1][c];
                if(c-1>=0)
                    dp[r][c] +=  dp[r][c-1];
            }
        }

        return dp[m-1][n-1];
    }
};