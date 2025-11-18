//order is maintained
#include<iostream>
#include<string>
#include<map>
using namespace std;

int main(){

    map<string, int> m;
    m["India"] = 150;
    m["Nepal"] = 15;
    m["US"] = 10;
    m["UK"] = 20;

    for(pair<string, int> p : m){
        cout<<p.first<<"   "<<p.second<<endl;
    }



    if(m.count("Nepal")){
        cout<<" Nepal IS PRESENT";
    }  else{
        cout<<"Nepal absent";
    }

    return 0;
}