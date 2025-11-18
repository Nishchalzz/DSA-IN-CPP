#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

int main(){

   unordered_set<int> s;
   s.insert(1);
   s.insert(5);
   s.insert(3);

   cout<<s.size()<<endl;
   s.erase(3);

    if(s.find(3) != s.end()){
        cout<<"Present \n";
    }else{
        cout<<"Not present \n";
    }

    for(auto it:s){
        cout<<it<<endl;
    }

    return 0;
}