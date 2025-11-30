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

    bool isBipartite(){

        vector<bool> vis(V, false);
        vector<int> color(V, -1);     //0 -- 1

        queue<int> q;
        q.push(0);
        vis[0]=true;
        color[0]=0;

        while(q.size()>0){
            int curr = q.front();
            q.pop();

            list<int> neighbours = l[curr];
            for(int v:neighbours){
                if(!vis[v]){
                    //not visit
                    color[v] = !color[curr];
                    vis[v]=true;
                    q.push(v);

                }else{
                    //visited before
                    if(color[v]==color[curr]){
                        return false;
                    }

                }
            }
        }

         return true;

    }

     bool isBipartiteWithoutvis_vector(){

       //not visit -1, visit - 0,1 based on color
        vector<int> color(V, -1);     //0 -- 1

        queue<int> q;
        q.push(0);
        color[0]=0;

        while(q.size()>0){
            int curr = q.front();
            q.pop();

            list<int> neighbours = l[curr];
            for(int v:neighbours){
                if(color[v]==-1){
                    //not visit
                    color[v] = !color[curr];
                    
                    q.push(v);

                }else{
                    //visited before
                    if(color[v]==color[curr]){
                        return false;
                    }

                }
            }
        }

         return true;

    }



};



int main(){

    Graph graph(10);


    // graph.addEdge(0,1);
    // graph.addEdge(0,2);
    // graph.addEdge(0,3);
    // graph.addEdge(1,2);
    // graph.addEdge(3,4);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(2,3);
    graph.addEdge(2,3);
    // graph.addEdge(0,3);

   

    cout<<graph.isBipartite()<<endl;
    cout<<graph.isBipartiteWithoutvis_vector();

    return 0;
}