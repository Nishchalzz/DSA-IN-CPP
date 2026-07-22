class Solution {
public:
    int helper(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(r == 0 && c == 0)
            return grid[r][c];
        if(r<0 || c<0)
            return INT_MAX;

        if(dp[r][c]!=-1) return dp[r][c];

        int left = 0;
        int up = 0;
    
        left = helper(r,c-1,grid,dp);
        
        if(left != INT_MAX)
            left += grid[r][c];

        up = helper(r-1,c,grid,dp);

        if(up != INT_MAX)
            up += grid[r][c];

        return dp[r][c] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,grid,dp);
    }
};