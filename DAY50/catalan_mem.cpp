#include<iostream>
#include<vector>
using namespace std;

int catalanmem(int n,vector<int>& dp){
    if(n==0 || n==1){
        return 1;
    }
    int ans = 0;
    if(dp[n]!=-1){
        return dp[n];
    }

    for(int i=0;i<n;i++){
        ans += catalanmem(i,dp) * catalanmem(n-i-1,dp);
    }
    dp[n] = ans;
    return ans;
}

int main(){
    int n=4;
    int ans = 0;
    vector<int> dp(n+1,-1);

    cout<<catalanmem(n,dp);

    return 0;
}