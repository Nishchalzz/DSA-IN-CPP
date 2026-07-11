class Solution {
public:
    //iscycle 
    bool dfs(int node, vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;

        for(auto it:adj[node]){
            if(!vis[it] && !pathvis[it]){
                if(dfs(it,adj,vis,pathvis))
                    return true;
            }else if(pathvis[it]){
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        for(int i=0;i<adj.size();i++){
            vector<int> pathvis(n,0);
            vector<int> vis(n,0);
            if(!dfs(i,adj,vis,pathvis))
                ans.push_back(i);
        }

        return ans;
    }
};