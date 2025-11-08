#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = right = NULL;
    }

};

static int idx = -1;

node* buildtree(vector<int> nodes){
    idx++;

    if(nodes[idx] == -1)
        return NULL;

    node* currNode = new node(nodes[idx]); //1
    currNode->left = buildtree(nodes);
    currNode->right = buildtree(nodes);

    return currNode;
}

void topView(node* root){

    queue<pair<node*, int>> q; //[(node, HD), (node, HD), (node, HD)......
    map<int, int> m; //(HD, NODE->DATA)

    q.push(make_pair(root, 0));

    while(!q.empty()){

        pair<node*, int> curr = q.front();
        q.pop();

        

        if(!m.count(curr.second))//HD check unique
        {
            m[curr.second] = curr.first->data;
        }

        if(curr.first->left!=NULL){
            q.push(make_pair(curr.first->left, curr.second-1));  //add left, hd-1
        }                                                        
        if(curr.first->right!=NULL){
            q.push(make_pair(curr.first->right, curr.second+1)); //add right, hd+1
        }
        

    }
    for(auto it:m){
        cout<<it.second<<"     \t";
    }

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    node* root = buildtree(nodes);

    topView(root);

    return 0;
}