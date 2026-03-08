#include<iostream>
#include<vector>
using namespace std;

int catalanrec(int n, int ans){
    if(n==0 || n==1){
        return 1;
    }
    ans = 0;

    for(int i=0;i<n;i++){
        ans += catalanrec(i,ans) * catalanrec(n-i-1,ans);
    }

    return ans;
}

int main(){
    int n;
    int ans = 0;

    cout<<catalanrec(4,ans);

    return 0;
}