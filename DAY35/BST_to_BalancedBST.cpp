
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};


void getInorder(Node* root, vector<int> &inorder){
    if(root==NULL)
        return;

    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}

Node* balancedTree(vector<int> &sorted, int start, int end){

    if(start>end)
        return NULL;

    int mid = start + (end-start)/2;

    Node* curr = new Node(sorted[mid]);
    curr->left = balancedTree(sorted, start, mid-1);
    curr->right = balancedTree(sorted, mid+1, end);

    return curr;
 

}

void preorder(Node* root){
    if(root == NULL)
        return;

    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}


int main(){

    Node* root = new Node(6);
    root->left = new Node(5);
    root->right = new Node(7);

    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right->right = new Node(8);
    root->right->right->right = new Node(9);


    vector<int> inorder;

    getInorder(root, inorder);

    root = balancedTree(inorder, 0, inorder.size()-1);

    preorder(root);

    return 0;
}