class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> ans;
        vector<int> adjrev[n];
        vector<int> indeg(n,0);
        queue<int> q;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjrev[it].push_back(i);
                indeg[i]++;
            }
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();

            for(auto it:adjrev[curr]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);   
            }

        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};