#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter the row no: ";
    cin>>n;

    // for(int i=1;i<=n;i++){
    //     for(int j=i;j<=n;j++){
    //         cout<<"*  ";
    //     }
    //     cout<<endl;
    // }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"*  ";
        }
        cout<<endl;
    }

    return 0;
}