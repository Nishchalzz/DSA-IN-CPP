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

Node* swapK(Node* head, int x, int y){
    if (x == y) return head; // same keys → no swap

    Node* prevX = NULL, *currX = head;
    while (currX && currX->data != x) {
        prevX = currX;
        currX = currX->next;
    }

    Node* prevY = NULL, *currY = head;
    while (currY && currY->data != y) {
        prevY = currY;
        currY = currY->next;
    }

    // If either node not found
    if (!currX || !currY) return head;

    // If x is not head
    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    // If y is not head
    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    // Swap next pointers
    Node* temp = currX->next;
    currX->next = currY->next;
    currY->next = temp;

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

    swapK(ll.head, 2,4);

    printList(ll.head);
    return 0;
}