#include<iostream>
#include<string>
#include<set>
using namespace std;

int main(){

   set<int> s;
   s.insert(1);
   s.insert(5);
   s.insert(3);
   s.insert(2);
   s.insert(7);

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