#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n+1;j++){
    //         if(i==1 | i==n){
    //             cout<<"*";
    //         }else{
    //             if(j==1 | j==n+1){
    //                 cout<<"*";
    //             }else{
    //                 cout<<" ";
    //             }
    //         }

    //     }
    //     cout<<endl;
    // }


    for(int i=1;i<=n;i++){
        cout<<"*";            
        for(int j=1;j<=n-1;j++){
            if(i==1 | i==n){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<"*";
        cout<<endl;
    }


    return 0;
}