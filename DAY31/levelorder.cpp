#include<iostream>
#include<vector>
#include<queue>
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

int main(){
    vector<int> nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    node* root = buildtree(nodes);

    levelorder(root);
    

    return 0;
}