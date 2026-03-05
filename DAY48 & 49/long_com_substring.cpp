#include<iostream>
#include<vector>
#include<string>
using namespace std;

int longestCommonSubstring(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int ans = 0;
    //dp[i][j] = long substring ending with i and j


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

int main(){
    string s1 = "abcde";
    string s2 = "abgce";

    cout<<longestCommonSubstring(s1,s2);

    return 0;
}