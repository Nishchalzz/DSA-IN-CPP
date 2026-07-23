class Solution {
public:
    int helper(int i, int j1,int j2,int n, int m,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp ){
        //j1 is robot 1 an dj2 is robot 2
        if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;

        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];

        if(i==n-1){
            //last row
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int delCol[] = {-1,0,1};
        int maxi = -1e8;
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++ ){
                if(j1==j2)
                    maxi = max(maxi,helper(i+1,j1+delCol[r],j2+delCol[c],n,m,grid,dp)+grid[i][j1]);
                else
                    maxi = max(maxi,helper(i+1,j1+delCol[r],j2+delCol[c],n,m,grid,dp)+grid[i][j1]+grid[i][j2]);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,n,m,grid,dp);
    }
};