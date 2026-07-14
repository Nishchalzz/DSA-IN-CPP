class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]}); // {v,w}, {v,w}
        }
        queue<pair<int,int>> q;

        vector<int> dist(n+1,INT_MAX);
        q.push({k,0});
        dist[k] = 0;
        int maxi=0;

        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int wt = it.second;
            q.pop();

            for(auto i:adj[node]){
                int neigh = i.first;
                int nweigh = i.second;

                if(nweigh+wt<dist[neigh]){
                    dist[neigh] = wt + nweigh;
                    q.push({neigh,dist[neigh]});
                }
            }
        }

        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX)
                return -1;
            maxi = max(dist[i],maxi);
        }

        return maxi;
        
    }
};