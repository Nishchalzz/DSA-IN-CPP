class disjointSet{
public:
	vector<int> par,rank,size;
	disjointSet(int n){
		par.resize(n);
		rank.resize(n,0);
        size.resize(n,1);
		for(int i=0;i<n;i++)
			par[i] = i;

	}
	
	int findPar(int node){
		if(node == par[node])
			return node;
		return par[node] = findPar(par[node]);
	}

	void unionByRank(int u, int v){
		int parU = findPar(u);
		int parV = findPar(v);
		if(parU == parV) return;
		if(rank[parU] > rank[parV]){
			par[parV] = parU;
		}else if(rank[parU] < rank[parV]){
			par[parU] = parV;
		}else{
			par[parV] = parU;
			rank[parU]++;
		}
	}

    void unionBySize(int u, int v){
        int parU = findPar(u);
        int parV = findPar(v);
        if(parU == parV) return;

        if(size[parU] > size[parV]){
            par[parV] = parU;
            size[parU] += size[parV];
        }else{
            par[parU] = parV;
            size[parV] += size[parU];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        disjointSet ds(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int node = i*n+j;
                if(grid[i][j]==1){
                    
                    //look four direction
                    int delrow[]={-1,0,1,0};
                    int delcol[]={0,1,0,-1};
                    for(int k=0;k<4;k++){
                        int newrow = i +delrow[k];
                        int newcol = j+delcol[k];
                        if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==1){
                            int newnode = newrow*n +newcol;
                            ds.unionBySize(node,newnode);
                        }
                    }
                }
            }
        } 

        //now try to get max area by toggling 0 (only one)
        int maxi = INT_MIN;
  
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int delrow[]={-1,0,1,0};
                    int delcol[]={0,1,0,-1};
                    vector<pair<int,int>> temppair;
                    int temp = 0;
                    unordered_set<int> parSet;
                    for(int k=0;k<4;k++){
                        int newrow = i +delrow[k];
                        int newcol = j+delcol[k];
                        
                        if(newrow>=0 && newrow<n && newcol>=0 && newcol<n && grid[newrow][newcol]==1){
                            int newnode = newrow*n +newcol;
                            int parr = ds.findPar(newnode);
                            temppair.push_back({parr,ds.size[parr]});
                            
                        }
                    }
                    // temppair -- (par,size)
                    for(auto it:temppair){
                        int tempPar = it.first;
                        int tempSize = it.second;
                        if(parSet.find(tempPar)==parSet.end()){
                            //not there unique
                            temp += tempSize;
                        } 
                        parSet.insert(tempPar);
                    }
                    maxi = max(temp+1, maxi);
                }
            }
        }
        int count = 0;
        for(int i=0;i<n*n;i++)
            if(ds.par[i]==i)
                count++;

        if(count>1)
            return maxi;
        return n*n;
    }
};