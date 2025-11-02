#include<iostream>
#include<string>
using namespace std;

void checkDup(string s, string res,int map[26], int i){
    
    int mapidx = (int)(s[i]-'a');

    if(i==s.size()){
        cout<<res<<endl;
        return;
    }

    if(map[mapidx]){
        checkDup(s,res,map,i+1);
    }else{
        map[mapidx]=true;
        checkDup(s,res+s[i],map,i+1);
    }

}

void checkDup(string s, string res,int map[26]){

    if(s.size()==0){
        cout<<res<<endl;
        return;
    }

    int n = s.size();
    char ch = s[n-1];
    int mapidx = (int)(s[n-1]-'a');

    s = s.substr(0,n-1);
    if(map[mapidx]){
        checkDup(s,res,map);
    }else{
        map[mapidx]=true;
        checkDup(s,res+ch,map);
    }

}

int main(){
    int map[26] = {false} ;
    string s = "appnnacollege";
    string res = "";
   
    // checkDup(s, res, map, 0);
    checkDup(s, res, map);
   
    return 0;
}