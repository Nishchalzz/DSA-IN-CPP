class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]}); // {v,w}, {v,w}
        }
        priority_queue<pair<int,int>> pq;

        vector<int> dist(n+1,INT_MAX);
        pq.push({0,k});
        dist[k] = 0;
        int maxi=0;

        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second;
            pq.pop();

            for(auto i:adj[node]){
                int neigh = i.first;
                int nweigh = i.second;

                if(nweigh+wt<dist[neigh]){
                    dist[neigh] = wt + nweigh;
                    pq.push({dist[neigh],neigh});
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