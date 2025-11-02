#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    int k;
    for(int i=1;i<=n;i++){
        k=i;
        //sp
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }
        //back num
        for(int j=i;j>=1;j--){
            cout<<j;
        }
        //forward num
        for(int j=2;j<=i;j++){
            cout<<j;
        }
        cout<<endl;
    }
    return 0;
}