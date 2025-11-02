#include<iostream>
#include<string>
using namespace std;

void perm(string str, string ans){
    int n = str.size();
    if(n==0){
        cout<<ans<<endl;
    }

   for(int i=0;i<str.size();i++){
        char ch = str[i];
        string newstr = str.substr(0,i)+str.substr(i+1, n-i-1);
        perm(newstr, ans+ch);
   }
}

int main(){
    perm("abc","");
    return 0;
}