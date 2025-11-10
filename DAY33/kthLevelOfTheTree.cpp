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

void KthHelper(node* root, int k, int currlvl){

    if(root==NULL)
        return;

    if(k==currlvl){
        cout<<root->data<<"\t";
        return;
    }

    KthHelper(root->left, k, currlvl+1);
    KthHelper(root->right, k, currlvl+1);

}

void KthLevel(node* root, int k){
    KthHelper(root, k, 1);
}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    node* root = buildtree(nodes);

    KthLevel(root, 3);

    return 0;
}