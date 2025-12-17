//finding minimum mst

#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *l;
    bool isUndirect;

public:
    Graph(int V, bool isUndirect=true){
        this->V = V;
        l = new list<pair<int, int>> [V];
        this->isUndirect=isUndirect;
    }

    void addEdge(int u, int v, int wt ){
        l[u].push_back(make_pair(v, wt));
        if(isUndirect){
            l[v].push_back(make_pair(u, wt ));
        }
        
    }

    void primsAlgo(int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
        //(wt, v) --> minHeap
        vector<bool> mst(V, false);
        // vector<pair<int,int>> incluEdge;

        pq.push(make_pair(0, src));
        int ans =0;

        while(pq.size()>0){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();  

            if(!mst[u]){
                mst[u] = true;
                ans += wt;
                

                list<pair<int, int>> neighbours = l[u];

                for(pair<int, int> n : neighbours){
                    int v = n.first;
                    int currwt = n.second;

                    pq.push(make_pair(currwt, v));
                }

            }
        }
        cout<<"Final cost of MST = "<<ans<<endl;

    }

};



int main(){

    Graph graph(4);

    graph.addEdge(0,1,10);
    graph.addEdge(0,2,15);
    graph.addEdge(0,3,30);

    graph.addEdge(1,3,40);

    graph.addEdge(2,3,50);

    graph.primsAlgo(0);

    return 0;
}