#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    vector<int> vec = {1,2,7,11,15,5,9};

   unordered_map<int, int> m;
   int target = 9; 

   for(int i=0;i<vec.size();i++){
        int comp = target - vec[i];
        if(m.count(comp)){
            cout<<i<<endl<<m[comp];
        }


        m[vec[i]] = i;
   }
    return 0;
}