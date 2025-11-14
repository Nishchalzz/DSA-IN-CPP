
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

Node* balancedTree(int arr[7], int start, int end){

    if(start>end)
        return NULL;

    int mid = start+(end-start)/2;

    Node* curr = new Node(arr[mid]);

    curr->left = balancedTree(arr, start, mid-1);
    curr->right = balancedTree(arr, mid+1, end);

    return curr;

}

void preorder(Node* root){
    if(root == NULL)
        return;

    cout<<root->data;
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node* root){
    if(root == NULL)
        return;

    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

int main(){
    int arr[7] = {3,4,5,6,7,8,9};

    Node* root = balancedTree(arr, 0, 6);

    preorder(root);

    return 0;
}