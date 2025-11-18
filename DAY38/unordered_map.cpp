#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){

    unordered_map<string, int> m;
    m["India"] = 150;
    m["Nepal"] = 15;
    m["US"] = 10;
    m["UK"] = 20;

    for(pair<string, int> p : m){
        cout<<p.first<<"   "<<p.second<<endl;
    }

    m.erase("Nepal");

    if(m.count("Nepal")){
        cout<<" Nepal IS PRESENT";
    }  else{
        cout<<"Nepal absent";
    }

    return 0;
}