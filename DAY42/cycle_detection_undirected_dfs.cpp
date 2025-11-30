#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<int> *l;

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
        for(int u=0;u<V;u++){
            list<int> neighbours = l[u];
            cout<<u<<" : ";
            for(int v: neighbours){
                cout<<v<<"  ";
            }
            cout<<endl;
        }
    }

    bool cycleHelperDFS(int src, vector<bool> &vis, int par){
        vis[src] = true;

        list<int> n = l[src];
        for(int v:n){
            if(!vis[v]){
                if(cycleHelperDFS(v, vis, src)) return true;
            }else{
                if(par != v){
                    return true;
                }
            }
        }

        return false;
    }

    bool cycleDFS(){
        int par = -1;
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cycleHelperDFS(i, vis, par)){
                    return true;
                }
            }
        }
        return false;
    }


};



int main(){

    Graph graph(10);


    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,8);
    graph.addEdge(3,7);
    graph.addEdge(0,2);
    graph.addEdge(2,5);
    graph.addEdge(5,0);

    graph.cycleDFS();


    return 0;
}