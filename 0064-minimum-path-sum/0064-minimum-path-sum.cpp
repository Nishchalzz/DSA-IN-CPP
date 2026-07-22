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

        vector<int> dp(m,-1);
        vector<int> temp(m,-1);
        temp[0] = grid[0][0];
 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i == 0 && j==0) continue;
                int left = INT_MAX;
                int up = INT_MAX;

                if(i-1>=0)
                    up = dp[j] + grid[i][j];
                if(j-1>=0)
                    left = temp[j-1] + grid[i][j];

                temp[j] = min(left,up);
            }
            dp = temp;
        }
        return temp[m-1];
    }
};