#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lsub(string s1, string s2,int n, int m, int count){
    if(n==0 || m==0 )
        return 0;

    if(s1[n-1] == s2[m-1]){ 
        count += lsub(s1,s2,n-1,m-1,count) + 1;
    }else{
        count += max(lsub(s1,s2,n-1,m,count), lsub(s1,s2,n,m-1,count));
    }

    return count;
}

int lsub_rec(string s1, string s2){
    int n = s1.size();
    int m = s2.size();

    if(n==0 || m==0 )
        return 0;

    if(s1[n-1] == s2[m-1]){ 
        return lsub_rec(s1.substr(0,n-1),s2.substr(0,m-1)) + 1;
    }else{
        return max(lsub_rec(s1.substr(0,n-1),s2), lsub_rec(s1,s2.substr(0,m-1)));
    }
}

int lsub_mem(string s1, string s2,vector<vector<int>>& dp){
    int n = s1.size();
    int m = s2.size();

    if(dp[n][m] != -1)
        return dp[n][m];

    if(n==0 || m==0 )
        return 0;

    if(s1[n-1] == s2[m-1]){ 
        dp[n][m] = lsub_mem(s1.substr(0,n-1),s2.substr(0,m-1),dp) + 1;
        
    }else{
        dp[n][m] = max(lsub_mem(s1.substr(0,n-1),s2,dp), lsub_mem(s1,s2.substr(0,m-1),dp));
        
    }

    return dp[n][m];
}


int lcsTab(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}


int main(){

    string s1 = "abcdge";
    string s2 = "abedg";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
    // cout<<lsub_rec(s1,s2);

    cout<<lsub_mem(s1,s2, dp);

    cout<<lcsTab(s1,s2);


    return 0;
}