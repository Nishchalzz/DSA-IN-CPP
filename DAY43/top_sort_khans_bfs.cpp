#include<iostream>
#include<list>
#include<vector>
#include<stack>
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

    void topHelp(int src, vector<bool> &vis, stack<int> &s){
        
        vis[src] = true;

        list<int> neighbours = l[src];
        for(int v:neighbours){
            if(!vis[v])
                topHelp(v, vis, s);
        }

        s.push(src);
    }

    void topSort(){
        vector<bool> vis(V, false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topHelp(i, vis, s);
            }
        }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }

    }

    void calcInDegree(vector<int> &indeg){
        for(int u=0;u<V;u++){
            list<int> neighbours = l[u];
            for(int v:neighbours){
                indeg[v]++;
            }
        }
    }

    void topSort2(){
        vector<int> indeg(V, 0);
        calcInDegree(indeg);
        queue<int> q;

        for(int i=0;i<V;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        while(q.size()>0){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            list<int> n =l[curr];
            for(int v:n){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }

        cout<<endl;
        
    }


};



int main(){

    //DAG

    Graph graph(6,false);

    graph.addEdge(2,3);
    graph.addEdge(3,1);

    
    graph.addEdge(4,0);
    graph.addEdge(4,1);


    graph.addEdge(5,0);
    graph.addEdge(5,2);

    
    graph.topSort2();
   

    return 0;
}