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

bool isIdentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    else if(root1 == NULL || root2 == NULL)
            return false;


    if(root1->data != root2->data)
        return false;

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
    
}

bool isSubtree(node* root, node* subroot){

    if(root == NULL && subroot == NULL)
        return true;
    else if(root == NULL || subroot == NULL)
            return false;
    

    if(root->data == subroot->data){
        if(isIdentical(root, subroot))
            return true;
    }

    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);

}

int main(){
    vector<int> n = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> n1 = {2,4,-1,-1,5,-1,-1};

    node* root = buildtree(n);
    idx = -1;
    node* subtreeRoot = buildtree(n1);

    cout<<isSubtree(root, subtreeRoot);

    return 0;
}