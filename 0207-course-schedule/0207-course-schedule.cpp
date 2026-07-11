class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> adj[n];
        vector<int> indeg(n,0);
        queue<int> q;

        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }   
        }

        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            count++;
            q.pop();

            for(auto it:adj[curr]){
                indeg[it]--;
                if(indeg[it] == 0)
                    q.push(it);
            }
        }

        if(count == n)
            return true;
        return false;

    }
};