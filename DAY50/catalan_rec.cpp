#include<iostream>
#include<vector>
using namespace std;

int catalanrec(int n){
    if(n==0 || n==1){
        return 1;
    }
    int ans = 0;

    for(int i=0;i<n;i++){
        ans += catalanrec(i) * catalanrec(n-i-1);
    }

    return ans;
}

int main(){
    int n;
    int ans = 0;

    cout<<catalanrec(4);

    return 0;
}