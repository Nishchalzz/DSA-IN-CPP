#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<climits>
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

static int mindif = INT_MAX;

// void minAbsDif(Node* root, int k){    O(N)

//     if(root == NULL)
//         return;

    
//     mindif = min(mindif, abs(root->data - k));
//     minAbsDif(root->left, k);
//     minAbsDif(root->right, k);

// }

void minAbsDif(Node* root, int k, int &minDif, Node* &minNode){

    if(root == NULL)
        return;

    if(root->data == k){
        minDif = 0;
        minNode = root;
        return;
    }

    if(minDif>abs(root->data - k)){
        minDif = abs(root->data - k);
        minNode = root;
    }

    if(k > root->data){
        minAbsDif(root->right,  k, minDif, minNode);

    }else{
        minAbsDif(root->left,  k, minDif, minNode);
    }
    
}

int main(){
    Node* root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(11);

    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->right = new Node(20);
    
    int minDif = INT_MAX;
    Node* newroot;

    
    minAbsDif(root,7, minDif, newroot);
    cout<<minDif;

    return 0;
}