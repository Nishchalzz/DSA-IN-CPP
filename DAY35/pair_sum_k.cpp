
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



bool search(Node* root, Node* temp, int need){

    if(root == NULL)
        return false;

    Node* c = root;
    bool flag = false;

    while(c!=NULL && flag!=true){
        if(c->data == need && c!=temp){
            flag = true;
            cout<<"pair 1: "<<c->data<<"  pair 2: "<<temp->data;
            return true;
        }

        else if(c->data<need)
            c = c->right;

        else if(c->data>need)
            c = c->left;
    }

    return false;

}

bool isPairPresent(Node* root, Node* temp, int target){
    if(temp == NULL)
        return false;

    return search(root, temp, (target - temp->data)) || isPairPresent(root, temp->left, target) || isPairPresent(root, temp->right, target);

}

int main(){
  
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    int k=6;

    cout<<endl<<isPairPresent(root1,root2,k);



    return 0;
}