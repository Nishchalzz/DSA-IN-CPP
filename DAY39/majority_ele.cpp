#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> vec = {1,3,2,5,1,3,1,5,1};

   unordered_map<int, int> m;

    //insert
   for(int i=0;i<vec.size();i++){
        if(!(m.count(vec[i]))){
            m[vec[i]]=1;
        }else{
            m[vec[i]]++;
            // cout<<m[vec[i]]<<endl;
        }
   }

   for(pair<int, int> p : m){
        //check the n/3 rule
        if(p.second>=vec.size()/3){
            cout<<p.first<<endl;
        }
   }


    return 0;
}