#include<iostream>
#include<list>
#include<vector>
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


};


//with weight
class GraphW{
    int V;
    list<pair<int, int>>* l;

public:
    GraphW(int V){
        this->V = V;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int w){
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }

    void print(){
        for(int i=0;i<V;i++){
            list<pair<int,int>> neighbours = l[i];
            cout<<i<<" : ";
            for(pair<int,int> ele:neighbours){
                cout<<"["<<ele.first<<" "<<ele.second<<"]"<<",";
            }
            cout<<endl;
        }
    }


};

int main(){
    // Graph graph(5);

    // graph.addEdge(0,1);
    // graph.addEdge(1,2);
    // graph.addEdge(2,3);
    // graph.addEdge(1,3);
    // graph.addEdge(2,4);
    
    // graph.print();


    GraphW graph(5);

    graph.addEdge(0,1,5);
    graph.addEdge(1,2,1);
    graph.addEdge(2,3,1);
    graph.addEdge(1,3,3);
    graph.addEdge(2,4,2);
    
    graph.print();


    return 0;
}