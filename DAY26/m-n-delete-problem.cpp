#include<iostream>
#include<string>
using namespace std;

class Node{

public:
    int data;
    Node* next;


    Node(int value){
        data = value;
        next = NULL;
    }


};

class List{
public:
    Node* head;
    Node* tail;



    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next = head;
            head = newNode;

        }

    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail = newNode;
        }
    }

    void printList(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }


    void pop_front(){
        if(head==NULL){
            cout<<"ll is empty";
            return;
        }

        Node* temp = head;

        head = head->next;

        temp->next=NULL;

        delete temp;

    }




};


void printList(Node* head){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
}

Node* deletemn(Node* head, int m, int n){
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        //retain m
        for(int i=0;i<m && temp!=NULL;i++){
            prev = temp;
            temp = temp->next;
        }
        
        //delete n
        for(int j=0;j<n && temp!=NULL;j++){
            Node* extra = temp;
            temp=temp->next;
            extra->next = NULL;
            delete extra;
        }
        if(prev != NULL){
            prev->next = temp;
        }
    }
    return head;
}


int main(){

    List ll;
    ll.push_front(9);
    ll.push_front(8);
    ll.push_front(7);
    ll.push_front(6);
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // ll.tail->next = ll.head;
    printList(ll.head);

    ll.head = deletemn(ll.head, 3,1);

    printList(ll.head);
    return 0;
}