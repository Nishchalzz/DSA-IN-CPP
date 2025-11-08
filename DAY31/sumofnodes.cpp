#include<iostream>
#include<vector>
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

int sumOfNodes(node* root){

    if(root == NULL)
        return 0;

    int left = sumOfNodes(root->left);
    int right = sumOfNodes(root->right);

    int currSum = left+right+(root->data);

    return currSum;

}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes1 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    node* root = buildtree(nodes);

    cout<<sumOfNodes(root)<<endl;

    return 0;
}