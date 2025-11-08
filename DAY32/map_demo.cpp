#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){

    map<int, string> m;
    m[101] = "rahul";
    m[102] = "neha";
    m[103] = "rahul";

    cout<<m[103]<<endl;
    cout<<m.count(104)<<endl;
    cout<<m.count(103)<<endl;

    for(auto it:m)
        cout<<it.first<<" \t "<<it.second<<endl;

    return 0;
}