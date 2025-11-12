
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
void inorder(Node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data;
    inorder(root->right);
}

Node* buildBST(int arr[], int n){
    Node* root = NULL; 
    for(int i=0;i<n;i++){
        root = insert(root, arr[i]);
    }

    return root;
    
}

void printVec(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<"\t";
    }
    cout<<endl;
}

void printRootToLeaf(Node* root, vector<int> &path){

    if(root == NULL)
        return;
    

    path.push_back(root->data);

    if(root->left == NULL && root->right==NULL){
        printVec(path);
        path.pop_back();
        return;
    }

    printRootToLeaf(root->left, path);
    
    printRootToLeaf(root->right, path);

    path.pop_back();

}       

int main(){
    int arr[9] = {8,5,3,1,4,6,10,11,14};

    Node* root = buildBST(arr, 9);

    vector<int> path;

    printRootToLeaf(root, path);

    return 0;
}