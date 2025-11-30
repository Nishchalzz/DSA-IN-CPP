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

int count(Node* root){

    int ans=0;

    for(auto &p:root->children){
        ans+=count(p.second);
    }

    return ans+1;

}

int countSubstr(string str){

    vector<string> vec;
    for(int i=0;i<str.size();i++){
        vec.push_back(str.substr(i));
    }

    Trie trie;

    for(int i=0;i<vec.size();i++){
        trie.insert(vec[i]);
    }

    return count(trie.getRoot());

}

int main(){
    
    cout<<countSubstr("ababa");

    return 0;
}