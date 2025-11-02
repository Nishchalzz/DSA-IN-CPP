#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
//upper part
    for(int i=1;i<=n;i++){
        //st
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //sp
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        //st
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;

    }
    //lower part
        for(int i=n;i>=1;i--){
        //st
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        //sp
        for(int j=1;j<=2*(n-i);j++){
            cout<<" ";
        }
        //st
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;

    }
    return 0;
}