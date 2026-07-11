class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indeg(n,0);
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }

        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int curr = q.front();
            ans.push_back(curr);
            q.pop();

            for(auto it:adj[curr]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }

        if(ans.size()!=n)
            return {};
        return ans;

    }
};