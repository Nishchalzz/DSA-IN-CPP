class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq; // dist,{r,c} all direc
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        if(grid[0][0]==1) return -1;

        pq.push({0,{0,0}});
        ans[0][0] = 0;


        while(!pq.empty()){
            int dist = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            int r[3] = {-1,0,1};
            int c[3] = {-1,0,1};

            for(int i:r){
                for(int j:c){
                    if(i==0 && j==0) continue;
                        int newrow = i+row;
                        int newcol = j+col;
                        if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol] == 0 && dist+1<ans[newrow][newcol]){
                            ans[newrow][newcol] = dist+1;
                            pq.push({dist+1,{newrow,newcol}});
                        }
                    }
                }
            
        }

        if(ans[n-1][m-1] != INT_MAX)
            return ans[n-1][m-1]+1;
        return -1;
    }
};