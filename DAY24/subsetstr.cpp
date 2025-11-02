#include<iostream>
#include<string>
using namespace std;

void func(string str, string subset){
    if(str==""){
        cout<<subset<<endl;
        return;
    }
    char ch = str[0];
    func(str.substr(1,str.size()-1), subset+ch);  //yes
    func(str.substr(1,str.size()-1), subset);  //no

}

int main(){
    func("abc","");
    return 0;
}