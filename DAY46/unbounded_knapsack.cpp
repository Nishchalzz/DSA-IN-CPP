#include<iostream>
#include<vector>
using namespace std;

int knapsack_unbound(int n, vector<int>& wt, vector<int>& val, int w){
    vector<vector<int>> dp(n+1, vector<int>(w+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            int currwt = wt[i-1];
            int currval = val[i-1];

            if(currwt<=j){
                dp[i][j] = max(currval+dp[i][j-currwt],dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j]; 
            }

        }
    }
    return dp[n][w];
    
}



int main(){

    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;

    cout<<knapsack_unbound(5,wt,val,w);

    return 0;
}