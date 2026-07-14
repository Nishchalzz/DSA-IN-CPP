class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<pair<int,int>> adj[n];

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto it = pq.top();
            int node = it.second;
            long dt = it.first;
            pq.pop();

            for(auto i:adj[node]){
                int neigh = i.first;
                int wt = i.second;
                if(dist[neigh]>wt+dt){
                    dist[neigh]=wt+dt;
                    ways[neigh] = ways[node];
                    pq.push({wt+dt,neigh});
                }else if(dist[neigh] == wt +dt){
                    ways[neigh] = (ways[neigh] + ways[node])%MOD;
                }    
            }  
        }

        return ways[n - 1];
    }
};