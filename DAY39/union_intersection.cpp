#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

void printUnion(vector<int> vec1, vector<int> vec2){
    unordered_set<int> s;

    for(int i=0;i<vec1.size();i++){
        s.insert(vec1[i]);
    }

    for(int i=0;i<vec2.size();i++){
        s.insert(vec2[i]);
    }

    for(int i:s){
        cout<<i<<"  ";
    }

}

void printIntersection(vector<int> vec1, vector<int> vec2){
    unordered_set<int> s;

    for(int el:vec1){
        s.insert(el);
    }
    
    for(int el:vec2){
        if(s.find(el) != s.end()){
            cout<<el<<" ";
            s.erase(el);
        }
    }

}


int main(){
    vector<int> vec1 = {7,3,9};
    vector<int> vec2 = {6,3,9,2,9,4};

    cout<<"Union: ";
    printUnion(vec1, vec2);
    cout<<endl;

    cout<<"Intersection: ";
    printIntersection(vec1, vec2);
    cout<<endl;
    
    
    return 0;
}