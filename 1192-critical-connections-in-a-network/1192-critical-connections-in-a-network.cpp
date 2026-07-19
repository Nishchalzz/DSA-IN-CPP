class Solution {

public:
    int timer = 1;
    
    void dfs(int node, int parent,vector<int>& vis, vector<int> adj[],   vector<int>& low,vector<int>& tins,vector<vector<int>>& ans){

        vis[node] = 1;
        low[node] = tins[node] = timer;
        timer++;

        for(auto it:adj[node]){
            if(it == parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,low,tins,ans);
                low[node] = min(low[it], low[node]);
                if(low[it] > tins[node]){
                    ans.push_back({node,it});
                }
            }else{
                low[node] = min(low[it], low[node]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        vector<int> low(n);
        vector<int> tins(n);
        vector<int> vis(n,0);
        vector<vector<int>> ans;
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,vis,adj,low,tins,ans);
        return ans;
    }
};