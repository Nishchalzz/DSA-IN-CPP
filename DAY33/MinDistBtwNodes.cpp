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

bool rootToNodePath(node* root, int n, vector<int> &path){
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);

    if(root->data == n){
        return true;
    }

    bool isLeft = rootToNodePath(root->left, n, path);
    bool isRight = rootToNodePath(root->right, n, path);

    if(isLeft || isRight){
        return true;
    }

    path.pop_back();
    return false;

}

int LCA(node*root, int n1, int n2){           //TC : O(N) , SC: O(N)
    vector<int> path1;
    vector<int> path2;

    rootToNodePath(root, n1, path1);
    rootToNodePath(root, n2, path2);

    int lca = -1;

    for(int i=0, j=0;i<path1.size() && j<path2.size();i++,j++){
        if(path1[i] != path2[j]){
            return lca;
        }
        lca = path1[i];
    }

    return lca;

}

node* LCA2(node* root, int n1, int n2){  //TC : O(N) , SC: O(1)

    if(root == NULL)
        return NULL;

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* leftLCA = LCA2(root->left, n1, n2);
    node* rightLCA = LCA2(root->right, n1, n2);

    if(leftLCA != NULL && rightLCA != NULL){
        return root;
    }

    return leftLCA == NULL ? rightLCA : leftLCA;

}

int dist(node* root, int n){

    if(root == NULL){
        return -1;
    }

    if(root->data == n){
        return 0;
    }

    int left = dist(root->left, n);
    if(left != -1){
        return left+1;
    }
    int right = dist(root->right, n);
    if(right != -1){
        return right+1;
    }

    return -1;

}

int minDistNodes(node* root, int n1, int n2){

    node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);

    return dist1+dist2;


}



int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    node* root = buildtree(nodes);

   cout<<minDistNodes(root, 4,5);

    return 0;
}