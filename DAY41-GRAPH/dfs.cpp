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

    void dfsHelper(int u, vector<bool> &vis){  //O(V+E)         //works for disconnected graph

        vis[u] = true;
        cout<<u<<"\t";

        list<int> neighbours = l[u];

        for(int v:neighbours){
            if(!vis[v]){
                dfsHelper(v, vis);
            }
        }
    }

    void dfs(){
        vector<bool> vis(7,false);
        for(int i=0;i<vis.size();i++){
            if(!vis[i])
                dfsHelper(i,vis);
                cout<<endl;
        }
        cout<<endl;
    }


};



int main(){
    Graph graph(10);

    // graph.addEdge(0,1);
    // graph.addEdge(0,2);
    // graph.addEdge(1,3);
    // graph.addEdge(2,4);
    // graph.addEdge(3,4);
    // graph.addEdge(3,5);
    // graph.addEdge(4,5);
    // graph.addEdge(5,6);

    graph.addEdge(1,6);
    graph.addEdge(6,4);
    graph.addEdge(4,9);
    graph.addEdge(4,3);
    graph.addEdge(3,8);
    graph.addEdge(3,7);
    graph.addEdge(0,2);
    graph.addEdge(2,5);


    
    
    graph.dfs();


    return 0;
}