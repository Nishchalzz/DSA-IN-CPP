class Solution {
public: 
    //return count of cities
    int dijkstraalgo(vector<pair<int,int>> adj[], int n, int src, int threshold){
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,src});
        dist[src] = 0;
        int count = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[v]>wt+d){
                    dist[v]=wt+d;
                    pq.push({dist[v],v});
                }
            }
        }
        for(int i=0;i<n;i++){
            if(dist[i] != INT_MAX && dist[i]<=threshold)
                count++;
        }
        return count;

    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges.size();
        vector<pair<int,int>> adj[n]; //{v,w}

        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int mini = INT_MAX;
        int idx = -1;
        for(int i = 0;i<n;i++){
            int c = dijkstraalgo(adj,n,i,distanceThreshold);
            if(c<=mini){
                mini = c;
                idx = i;
            }
        }
        return idx;
    }
};