#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int count_distinct(vector<int> vec){
    unordered_set<int> s;
    for(int i=0;i<vec.size();i++){
        s.insert(vec[i]);
    }

    for(int el:s){
        cout<<el<<"   ";
    }

    return s.size();
}

int main(){
    vector<int> vec = {1,3,2,5,1,3,1,5,1};

    cout<<count_distinct(vec);
    return 0;
}