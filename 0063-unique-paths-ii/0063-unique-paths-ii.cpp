class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(r==0 && c==0 && obstacleGrid[r][c] == 0)
            return 1;
        
        if(r<0 || c<0 || obstacleGrid[r][c] == 1) return 0;

        if(dp[r][c]!=-1) return dp[r][c];

        return dp[r][c] = helper(r-1,c,obstacleGrid,dp) + helper(r,c-1,obstacleGrid,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1, m-1,obstacleGrid,dp);
    }
};