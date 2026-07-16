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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size(); // no of ele
        disjointset ds(n);
        unordered_map<int,int> rowMap;
        unordered_map<int,int> colMap;

        for(int i=0;i<n;i++){
            int row = stones[i][0];
            int col = stones[i][1];

            if(rowMap.count(row))
                ds.unionByRank(i,rowMap[row]);
            else 
                rowMap[row] = i;

            if(colMap.count(col))
                ds.unionByRank(i,colMap[col]);
            else 
                colMap[col] = i;
        }
        
        int count = 0;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i)
                count++;
        }
        return n-count;
    }
};