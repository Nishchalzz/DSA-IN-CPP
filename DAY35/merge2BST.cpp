
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

void inorderToVec(Node* root, vector<int> &vec){
    if(root==NULL)
        return;

    inorderToVec(root->left, vec);
    vec.push_back(root->data);
    inorderToVec(root->right, vec);

}

Node* vecToBalancedTree(vector<int> vec, int start, int end){
    
    int mid = start + (end-start)/2;

    if(start>end)
        return NULL;

    Node* curr = new Node(vec[mid]);
    curr->left = vecToBalancedTree(vec, start, mid-1);
    curr->right = vecToBalancedTree(vec, mid+1, end);

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
  
    Node* root1 = new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left = new Node(3);
    root2->right = new Node(12);

    vector<int> vec;

    inorderToVec(root1, vec);
    inorderToVec(root2, vec);

    sort(vec.begin(), vec.end());

    Node* root = vecToBalancedTree(vec,0,vec.size()-1);

    

    preorder(root);



    return 0;
}