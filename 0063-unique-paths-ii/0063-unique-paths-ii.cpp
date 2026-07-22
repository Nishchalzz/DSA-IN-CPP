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
        vector<int> dp(m,-1);
        vector<int> temp(m,-1);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0 && obstacleGrid[i][j] == 0){
                    temp[j] = 1;
                    continue;
                }

                if(i==0 && j==0 && obstacleGrid[i][j] == 1){
                    temp[j] = 0;
                    continue;
                }

                int left = 0; int up = 0;
                if(j-1>=0 && obstacleGrid[i][j] == 0)
                    left = temp[j-1];
                if(i-1>=0 && obstacleGrid[i][j] == 0)
                    up =  dp[j];
                temp[j] = left + up;
            }
            dp = temp;
        }

        return temp[m-1];
    }
};