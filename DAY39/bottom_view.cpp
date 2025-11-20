#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
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

void printBottom(Node* root){
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));
    unordered_map<int, int> m;

    while(!q.empty()){
        pair<Node*, int> p = q.front();
        q.pop();
        m[p.second] = p.first->data;

        if(p.first->left != NULL){
            q.push(make_pair( p.first->left, p.second-1));
        }

        if(p.first->right != NULL){
            q.push(make_pair( p.first->right, p.second+1));
        }


    }
    for(pair<int, int> p:m){
        cout<<p.second<<" ";
    }




}



int main(){

    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(25);

    root->left->left = new Node(5);
    root->left->right = new Node(3);

    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);


    printBottom(root);

    
    return 0;
}