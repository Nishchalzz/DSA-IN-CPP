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

    void longestHelper(Node* root, string &ans, string temp){
        for(pair<char, Node*> child:root->children){

            if(child.second->endOfWord){
                temp += child.first;

                if(((temp.size() == ans.size()) && temp<ans) || (temp.size()>ans.size())){
                    ans = temp;
                }

                longestHelper(child.second, ans, temp);

                temp = temp.substr(0,temp.size()-1);
            }


        }
    }

    string longestwordwitheow(){

        string ans = "";
        longestHelper(root, ans, "");
        return  ans;

    }

    Node* getRoot(){
        return root;
    }

};

string longestWord(vector<string> dict){
    Trie trie;

    for(int i=0;i<dict.size();i++){
        trie.insert(dict[i]);
    }

    return trie.longestwordwitheow();

}



int main(){
    
   vector<string> dict = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    cout<<longestWord(dict);

    return 0;
}