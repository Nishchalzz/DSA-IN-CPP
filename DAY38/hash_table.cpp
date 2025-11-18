#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Node{
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node(){
        if(next != NULL)
            delete next;
    }
};

class HashTable{

    int totalSize;
    int currSize;
    Node** table;

    int hashFunction(string key){
        int idx = 0;
        for(int i=0;i<key.size();i++){
            idx += (key[i]*key[i])%totalSize;
        }
        return idx%totalSize;
    }

    void rehash(){    //O(n)
        Node** oldTable = table;
        int oldSize = totalSize;

        totalSize = 2*oldSize;
        currSize = 0;

        table = new Node*[totalSize];
        for(int i=0;i<totalSize;i++){
            table[i] = NULL;
        }

        //copy
        for(int i=0;i<oldSize;i++){
            Node* temp = oldTable[i];
            while(temp!=NULL){
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete[] oldTable;

    }

public:
    
    HashTable(int size = 5){
        this->totalSize = size;
        currSize = 0;

        table = new Node*[size];
        for(int i=0;i<size;i++){
            table[i] = NULL;
        }
    }

    void insert(string key, int val){  //O(1) - avg case
        int idx = hashFunction(key);

        
        Node* newNode = new Node(key, val);

        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize/(double)totalSize;
        if(lambda > 1){
            rehash();    //O(n) - worst case
        }

    }

    bool exists(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];

        while(temp!=NULL){
            if(temp->key == key)
                return true;
            temp = temp->next;
        }

        return false;

    }


    int search(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];

        while(temp!=NULL){
            if(temp->key == key)
                return temp->val;
            temp = temp->next;
        }

        return -1;
    }

    void remove(string key){
        int idx = hashFunction(key);
        Node* temp = table[idx];
        Node* prev = temp;
        while(temp!=NULL){
            if(temp->key == key){
                //found it, now remove
                if(temp==prev){
                    table[idx] = temp->next;
                }else{
                    prev->next = temp->next;
                }
                break;
            }

            prev = temp;
            temp = temp->next;
        }
    }  


    void print(){
        for(int i=0;i<totalSize;i++){
            Node* temp = table[i];
            cout<<"IDX: "<<i<<"\t";
            while(temp!=NULL){
                cout<<"( "<<temp->key<<", "<<temp->val<<")  -->  ";
                temp = temp->next;
            }
            cout<<endl;

        }
    }
};


int main(){
    HashTable ht;
    ht.insert("India",150);
    ht.insert("China",150);
    ht.insert("US",50);
    ht.insert("Canada",150);
    ht.insert("UK",20);

    // if(ht.exists("India")){
    //     cout<<ht.search("India")<<endl;
    // }

    // ht.print();

    ht.remove("China");

    ht.print();

    return 0;
}