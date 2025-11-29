#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;

class Node{
public:
    unordered_map<char, Node*> children;
    bool endOfWord;

    Node(){
        endOfWord=false;
    }
} ;

class Trie{
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string key){
        Node* temp = root;
        for(int i=0;i<key.size();i++){
            if(!temp->children.count(key[i])){
                temp->children[key[i]] = new Node();
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key){
        Node* temp = root;
        for(int i=0; i<key.size();i++){
            if(temp->children.count(key[i])){
                temp = temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;

    }

    bool startsWithPrefix(string prefix){
        Node* temp = root;
        for(int i=0;i<prefix.size();i++){
            if(!temp->children.count(prefix[i])){
                return false;
            }
            temp = temp->children[prefix[i]];
        }

        return true;
    }

    Node* getRoot(){
        return root;
    }

};

void anagram(vector<string> vec){

    Trie trie;
    for(int i=0;i<vec.size();i++){
        trie.insert(vec[i]);
    }

    


}



int main(){
    
    vector<string> vec = {"eat","tea","tan","ate","nat","bat"};



    return 0;
}