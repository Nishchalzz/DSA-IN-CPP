class disjointset{
public:
    vector<int> rank,par;
    disjointset(int n){
        rank.resize(n,0);
        par.resize(n);
        for(int i=0;i<n;i++)
            par[i] = i;
    }

    int findPar(int node){
        if(par[node] == node)
            return node;
        return par[node] = findPar(par[node]);
    }

    void unionByRank(int u,int v){
        int parU = findPar(u);
        int parV = findPar(v);
        if(parU == parV) return;

        if(rank[parU] > rank[parV]){
            par[parV] = parU;
        }else if(rank[parV] > rank[parU]){
            par[parU] = parV;
        }else{
            par[parU] = parV;
            rank[parV]++;
        }
    }

};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointset ds(n*n);
        vector<pair<int,int>> pos(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                pos[grid[i][j]]={i,j};
            }
        }
        vector<vector<bool>> open(n,vector<bool>(n,false));
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        int t;
        for(t=0;t<n*n;t++){
            int row = pos[t].first;
            int col = pos[t].second;
            int node = row*n+col;
            open[row][col] = true;

            for(int i=0;i<4;i++){
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                int newnode = newrow*n+newcol;
                if(newrow>=0 && newrow<n && newcol>=0 && newcol < n && open[newrow][newcol] == true){
                        ds.unionByRank(newnode,node);
                }   
            }
            if(open[0][0] == true && open[n-1][n-1] == true && ds.findPar(0) == ds.findPar(n*n-1))
                return t;
        }


        return -1;
    }
};