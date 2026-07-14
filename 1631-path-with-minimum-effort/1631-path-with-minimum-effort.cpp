class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        pq.push({0,{0,0}});
        dist[0][0] = 0;

        int final = INT_MAX;

        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int effort = pq.top().first;
            pq.pop();

            if(row == n-1 && col == m-1)
                final = min(effort,final);

            int delrow[] = {-1,0,1,0}; 
            int delcol[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newr = row+delrow[i];
                int newc = col+delcol[i];



                if(newr>=0 && newr<n && newc>=0 && newc<m){
                    int absdiff = abs(heights[row][col] - heights[newr][newc]);
                    int neweffort = max(effort,absdiff);
                    if(absdiff<dist[newr][newc]){
                        dist[newr][newc] = absdiff;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
        return final;


    }
};