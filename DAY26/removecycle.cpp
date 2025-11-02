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

bool removecycle(Node* head){
    //detect cycle
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow){
            isCycle = true;
            cout<<"Cycle Exists";
            break;
        }
    }
    slow = head;
    if(!isCycle){
        cout<<"Cycle doesnot exists";
        return false;
    }

    if(fast == slow){
        while(slow!=fast->next){
            fast = fast->next;
        }
        fast->next = NULL;
    }else{
            Node* prev = fast;
        while(fast != slow){
            prev = fast;
            fast = fast->next;
            slow = slow->next;
        }
        prev -> next = NULL;
    }
}

int main(){

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head;

    removecycle(ll.head);
    ll.printList();
    return 0;
}