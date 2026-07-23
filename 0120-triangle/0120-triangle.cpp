class Solution {
public:
    int helper(int r,int c, int n,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(r==n-1)
            return triangle[r][c];

        if(dp[r][c]!=-1) return dp[r][c];
        
        int down = helper(r+1,c,n,triangle,dp)+triangle[r][c];
        int diag = helper(r+1,c+1,n,triangle,dp)+triangle[r][c];

        return dp[r][c]=min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();
        vector<vector<int>> dp(r,vector<int>(c,-1));
        
        for(int i=0;i<c;i++)
            dp[r-1][i]  = triangle[r-1][i];
        
        for(int i=r-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diag);
            }
        }


        return dp[0][0];
    }
};