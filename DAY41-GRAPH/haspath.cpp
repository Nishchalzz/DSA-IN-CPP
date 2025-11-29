#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;


//without weight
class Graph{
    int V;
    list<int>* l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            list<int> neighbours = l[i];
            cout<<i<<" : ";
            for(int ele:neighbours){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }

    bool hasPathHelperDfs(int src, int dest, vector<bool> &vis){  //o(V+E)
        if(src == dest)
            return true;

        vis[src] = true;

        list<int> n = l[src];
        for(int v:n){
            if(!vis[v]){
                if(hasPathHelperDfs(v,dest, vis)){
                    return true;
                }
            }
        }
        return false;
    }

    bool hasPathHelperBfs(int dest, vector<bool> &vis){
        queue<int> q;
        q.push(0);
        vis[0] = true;

        while(q.size()>0){
            int u = q.front();
            q.pop();

            list<int> neighbours = l[u];
            for(int v:neighbours){
                if(!vis[v]){
                    vis[v] = true;
                    q.push(v);
                    if(v==dest)
                        return true;
                }
            }

        }
        return false;


    }

    bool hasPath(int src, int dest){
        vector<bool> vis(7,false);
        // return hasPathHelperDfs(src, dest, vis);
        return hasPathHelperBfs(dest, vis);
    }


};



int main(){
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    
    cout<<graph.hasPath(0,6);
    

    return 0;
}