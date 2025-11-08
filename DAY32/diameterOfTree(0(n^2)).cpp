#include<iostream>
#include<vector>
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

int height(node* root){ //O(n)

    if(root==NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;

}

int diameter(node* root){ //O(n^2)

    if(root==NULL)
        return 0;

    int currdia = height(root->left) + height(root->right) + 1; //O(n)
    int left = diameter(root->left);
    int right = diameter(root->right);

    return max(currdia, max( left, right));

}


int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes1 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    node* root = buildtree(nodes);

    cout<<diameter(root);

    return 0;
}