#include<iostream>
#include<string>
using namespace std;

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = next = NULL;
    }
};

class DoublyList{
public:
    Node* head;
    Node* tail;

    DoublyList(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head = tail = newNode;
        }else{
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front(){
        Node* temp = head;
        head = head -> next;
        if(head!=NULL){
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    void pop_back(){
        void pop_back() {
    if (tail == NULL) return; // empty list

    Node* temp = tail;

    if (head == tail) { // only one node
        head = tail = NULL;
    } else { // more than one node
        tail = tail->prev;
        tail->next = NULL;
    }

    delete temp;
}

        
    }

    void printll(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" <-> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

};


int main(){
    DoublyList dbll;

    dbll.push_front(4);
    dbll.push_front(3);
    dbll.push_front(2);
    dbll.push_front(1);

    dbll.printll(dbll.head);

    dbll.pop_front();
    dbll.pop_back();
    
    dbll.printll(dbll.head);

    dbll.push_back(7);
    
    dbll.printll(dbll.head);
}