#include<iostream>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

class Graph{
    int V;
    list<int> *l;
    bool isUndirect;

public:
    Graph(int V, bool isUndirect=true){
        this->V = V;
        l = new list<int> [V];
        this->isUndirect=isUndirect;
    }

    void addEdge(int u, int v){
        l[u].push_back(v);
        if(isUndirect){
            l[v].push_back(u);
        }
        
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

    void pathHelper(int src, int dest, vector<bool> &vis, string &path){

        if(src == dest){
            cout<<path<<dest<<endl;
            return;
        }


        vis[src] = true;
        path += to_string(src);

        list<int> neighbours = l[src];

        for(int v:neighbours){
            if(!vis[v]){
                pathHelper(v,dest, vis, path);
            }
        }

        vis[src] = false;
        path = path.substr(0,path.size()-1);


    } 

    // void pathHelperbfs(int src, int dest, vector<bool> &vis, string &path){
    //     queue<int> q;
    //     vis[src] = true;
    //     path += src;
    //     q.push(src);

    //     while(q.size()>0){
    //         if(src == dest){
    //             cout<<path<<dest<<endl;
    //         }

    //         int curr = q.front();
            
    //         q.pop();
            
    //         list<int> neighbours = l[curr];
    //         for(int v:neighbours){
    //             if(!vis[v]){
    //                 q.push(v);
    //                 path += src;
    //             }
    //         }

    //     }
        

    // }

    void printAllPaths(int src, int dest){
        vector<bool> vis(V, false);
        string path = "";
        // pathHelper(src, dest, vis, path);
        // pathHelperbfs(src,dest,vis,path);
    }


};



int main(){

    Graph graph(6,false);


    graph.addEdge(3,1);
    graph.addEdge(2,3);
    graph.addEdge(0,3);
    graph.addEdge(4,0);
    graph.addEdge(4,1);
    graph.addEdge(5,0);
    graph.addEdge(5,2);

    
    graph.printAllPaths(5,1);
   

    return 0;
}