class disjointset{
private:
    vector<int> rank,par;
public:
    disjointset(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i] = i;
    }

    int findpar(int node){
        if(node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }

    void unionbyrank(int u, int v){
        int ult_par_u = findpar(u);
        int ult_par_v = findpar(v);

        if(ult_par_u == ult_par_v) return;

        if(rank[ult_par_u] > rank[ult_par_v])
            par[ult_par_v] = ult_par_u;
        else if(rank[ult_par_v] > rank[ult_par_u])
            par[ult_par_u] = ult_par_v;
        else if(rank[ult_par_v] == rank[ult_par_u]){
            par[ult_par_u] = ult_par_v;
            rank[ult_par_v]++;
        }

    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int totalEdge = connections.size();
        int components = n;
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            int parU = ds.findpar(u);
            int parV = ds.findpar(v);

            if(parU == parV) continue;
            else{
                ds.unionbyrank(u,v);
                components--;
            }
        }
        //extra edges is count extra , count connection == nodes+1
       if(totalEdge<n-1)
            return -1;

        return components-1;
    }
};