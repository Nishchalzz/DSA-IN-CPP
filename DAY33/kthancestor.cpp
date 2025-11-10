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

int kthAncestor(node* root, int node, int k){
    if(root==NULL)
        return -1;

    if(root->data == node)
        return 0;

    int left = kthAncestor(root->left, node, k);
    int right = kthAncestor(root->right, node, k);

    if(left == -1 && right == -1)
        return -1;
    
    int validval = left == -1? right:left;

    if(validval + 1 == k)
        cout<<"Ancestor: "<<root->data;
    
    return validval+1;
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    node* root = buildtree(nodes);

   kthAncestor(root, 5, 2);

    return 0;
}