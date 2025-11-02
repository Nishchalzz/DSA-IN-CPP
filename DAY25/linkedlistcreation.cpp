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

    ~Node(){
        if(next!=NULL){
            // cout<<"~node "<<data<<endl;
            delete next;
            next = NULL;
        }
    }

};

class List{

    Node* head;
    Node* tail;

public:

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

    void insert(int val, int pos){
        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i=0;i<pos-1;i++){
            if(temp == NULL){
                cout<<"Doesnt exist";
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
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

    void pop_back(){
        Node* temp = head;
        while(temp->next->next != NULL){
            temp=temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    int searchitr(int key){
        Node* temp = head;
        int idx = 0;
        while(temp!=NULL){
            if(temp->data == key){
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        return -1;
    }
    int helper(Node* head, int key){
        if(head==NULL){
                return -1;
        }

        if(head->data == key)
            return 0;
        int idx = helper(head->next, key);
        if(idx == -1){
            return -1;
        }
        return idx+1;
    }

    int searchrec(int key){
        return helper(head, key);
    }

    void reverse(){
        Node* prev = NULL;
        Node* curr = head;
        tail = head;
        while(curr != NULL){
            Node* next = curr->next;
            curr->next = prev;

            //updation
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void removenth(int n){
        Node* temp = head;
        int size = 0;
        while(temp != NULL){
            size++;
            temp = temp->next;
        }
        size = size - n;
        Node* prev = head;
        for(int i=1;i<size;i++){
            prev = prev->next;
        }
        prev->next = prev->next->next;
    }

    ~List(){
        if(head!=NULL){
            // cout<<"~List\n";
            delete head;
            head = NULL;
        }
    }

};

int main(){
    List ll;

    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // ll.push_back(4);
    // ll.push_back(5);
    // ll.insert(100,2);
    // // ll.pop_back();
   
    // cout<<ll.searchitr(1)<<endl;
    // cout<<ll.searchrec(3)<<endl;
    // ll.reverse();
    ll.removenth(1);
    ll.printList();

    return 0;
}