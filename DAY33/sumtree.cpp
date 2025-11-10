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

int sumTree(node* root){  //my answer

    if(root == NULL)
        return 0;
    
    int left = sumTree(root->left);
    int right = sumTree(root->right);

    if(left == 0 && right == 0){
        int temp = root->data;
        root->data = 0;
        return temp;
    }else{
        int temp = root->data;
        root->data = left+right+temp;
        return left+right+temp;
    }
        

}

int transform(node* root){    //shraddha answer
    if(root==NULL)
        return 0;

    int leftold = transform(root->left);
    int rightold = transform(root->right);
    int currold = root->data;

    root->data = leftold + rightold ;

    if(root->left!=NULL)
        root->data += root->left->data;

    if(root->right!=NULL)
        root->data += root->right->data;

    return currold;
}
void levelorder(node* root){
    if(root == NULL)
        return;

    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){


        node* curr = q.front();
        q.pop();

        if(curr==NULL){

            cout<<"\n";

            if(q.empty()){
                break;
            }
            
            q.push(NULL);
            continue;

        }
    
        cout<<curr->data<<"\t";

        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
}
void preorder(node* root){

    if(root == NULL){
        return;
    }

    cout<<root->data<<"\t";
    preorder(root->left);
    preorder(root->right);
}



int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    node* root = buildtree(nodes);

   

   transform(root);

   levelorder(root);
    return 0;

}