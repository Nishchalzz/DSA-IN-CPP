#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    
    for(int i=1;i<=n;i++){
        //sp
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        //st
        for(int j=1;j<=(2*i-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }

    for(int i=n;i>=1;i--){
        //sp
        for(int j=1;j<=n-i;j++)
            cout<<" ";
        //st
        for(int j=1;j<=(2*i-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}