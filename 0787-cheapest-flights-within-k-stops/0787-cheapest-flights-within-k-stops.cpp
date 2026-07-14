class Solution {
public:
    int findCheapestPrice(int nnode, vector<vector<int>>& flights, int src, int dst, int k) {
        int n = flights.size();
        int m = flights[0].size();
        vector<pair<int,int>> adj[nnode];
        queue<pair<int,pair<int,int>>> q; // (stops,(node,wt))
        //adj done
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(nnode,INT_MAX);

        q.push({0,{src,0}});
        dist[src] = 0;

        while(!q.empty()){
            int node = q.front().second.first;
            int currk = q.front().first;
            int wt = q.front().second.second;
            q.pop();


            for(auto it:adj[node]){
                int ele = it.first;
                int wtele = it.second;

                if(currk+1 <= k+1 && dist[ele] > wtele + wt){
                    dist[ele] = wtele + wt;
                    q.push({currk+1, {ele, dist[ele]}});
                }
            }
        }

        if(dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};