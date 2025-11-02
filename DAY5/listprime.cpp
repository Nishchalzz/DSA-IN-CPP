#include<iostream>
#include<cmath>
using namespace std;

//prints all the prime numbers from 2 to N

int main(){
    int n;
    cout<<"Enter the number n: ";
    cin>>n;
    for(int i=2;i<=n;i++){
        bool flag=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                flag=false;
            }
        }
        if(flag){
            cout<<i<<"  ";
        }
    }
    return 0;
}