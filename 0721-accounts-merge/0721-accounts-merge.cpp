class disjointset{
public:
    vector<int> par,rank;
    disjointset(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            par[i] = i;
    }
    int findPar(int node){
        if(node == par[node])
            return node;
        return par[node] = findPar(par[node]); //compression + findpar
    }
    void unionByRank(int u, int v){
        int parU = findPar(u);
        int parV = findPar(v);
        if(parU == parV)
            return;
        if(rank[parU] < rank[parV]){
            par[parU] = parV;
        }else if(rank[parU] > rank[parV]){
            par[parV] = parU;
        }else if(rank[parU] == rank[parV]){
            par[parU] = parV;
            rank[parV]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> final;
        int n = accounts.size();
        disjointset ds(n);  // all name as 0-n-1
        unordered_map<string, int> mailToNode;
        //map mail to node formation
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mailToNode.find(mail) != mailToNode.end()){
                    ds.unionByRank(i,mailToNode[mail]);
                }else{
                    mailToNode[mail] = i;
                }

            }
        }
        //create merged mail
        vector<string> mergedmail[n];
        for(auto it:mailToNode){
            string mail = it.first;
            int node = it.second;
            int parent = ds.findPar(node);
            mergedmail[parent].push_back(mail);
        }
        //create final ans
        for(int i=0;i<n;i++){
             if (mergedmail[i].empty()) continue;
            vector<string> ans;
            ans.push_back(accounts[i][0]);
            sort(mergedmail[i].begin(), mergedmail[i].end());
            for(auto it:mergedmail[i]){
                ans.push_back(it);
            }
            final.push_back(ans);
        }
        sort(final.begin(),final.end());
        return final;
    }
};