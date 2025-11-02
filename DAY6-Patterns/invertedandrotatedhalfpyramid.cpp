#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the n: ";
    cin>>n;

    for(int i=1;i<=n;i++){
        // for(int j=i;j<=n-1;j++){
        //         cout<<" ";
        // } or 
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    return 0;
}