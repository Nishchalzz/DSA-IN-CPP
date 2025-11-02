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

bool isCycle(Node* head){
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow){
            cout<<"Cycle Exists";
            return true;
        }

    }
    cout<<"Cycle Does not Exist";
    return false;
}

int main(){

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    // ll.tail->next = ll.head;

    isCycle(ll.head);
    return 0;
}