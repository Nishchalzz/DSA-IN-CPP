#include<iostream>
#include<String>
using namespace std;

void toi(int n, string src, string help, string dest){
    if(n==1){
        cout<<"move "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    toi(n-1,src,dest,help);
    cout<<"move disk "<<n<<"from "<<src<<"to"<<dest<<endl;
    toi(n-1,help,src,dest);
}

int main(){
    toi(3,"A","B","C");
    return 0;
}

