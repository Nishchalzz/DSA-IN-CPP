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

Node* insert(Node* root, int val){  //0(height)  == logn
    if(root==NULL){
        root = new Node(val);
        return root;
    }

    if(val<root->data){
        root->left = insert(root->left, val);
    }else{
        root->right = insert(root->right, val);
    }

    return root;

}


Node* buildBST(int arr[], int n){
    Node* root = NULL; 
    for(int i=0;i<n;i++){
        root = insert(root, arr[i]);
    }

    return root;
    
}

Node* inorderSuccessor(Node* root){
    while(root->left!=NULL)
        root=root->left;
    return root;
}

Node* deleteNode(Node* root, int val){
    if(root == NULL)
        return NULL;
    
    if(val<root->data){
        root->left = deleteNode(root->left, val);
    }
    else if(val>root->data){
        root->right = deleteNode(root->right, val);
    }
    else{
        //case 1 - NULL
        if(root->right == NULL && root->left==NULL){
            delete root;
            return NULL;
        }

        //CASE 2 ONE CHILD
        else if(root->right == NULL || root->left==NULL){
            return root->right==NULL?root->left:root->right;
        }

        //CASE 3 TWO CHILD
        else{
            Node* IS = inorderSuccessor(root->right);
            root->data = IS->data;
           
            root->right = deleteNode(root->right, IS->data);
            return root;
            
        }
    }
    return root;

}

void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<"\t";
    inorder(root->right);
}

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr, 9);
    inorder(root);
    cout<<endl;
    deleteNode(root, 5);
    inorder(root);
    
    
    return 0;
}