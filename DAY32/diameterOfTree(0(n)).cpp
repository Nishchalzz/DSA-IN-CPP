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


pair<int, int> diameter(node* root){ //O(n)

    //first->diam, second->height
    //(diam, height)
    
    if(root == NULL)
        return make_pair(0,0);


    pair<int, int> leftInfo = diameter(root->left);
    pair<int, int> rightInfo = diameter(root->right);

    int curr = leftInfo.second + rightInfo.second +1;
    int finalDiam = max(curr , max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second, rightInfo.second)+1;


    return make_pair(finalDiam, finalHt);

}

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    vector<int> nodes1 = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    node* root = buildtree(nodes1);

    cout<<diameter(root).first;

    return 0;
}