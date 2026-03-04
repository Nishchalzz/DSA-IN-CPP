#include<iostream>
#include<vector>
using namespace std;

int knapsack_rod(vector<int> prices, vector<int> length, int rodlength){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(rodlength+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=rodlength;j++){
            int currwt = length[i-1];
            int currval = prices[i-1];

            if(currwt<=j){
                dp[i][j] = max(dp[i][j-currwt]+currval, dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][rodlength];
}


int main(){

    vector<int> prices = {1, 5, 8,9,10,17,17,20};
    vector<int> length = {1,2,3,4,5,6,7,8};
    int rodLength = 8;

    cout<<knapsack_rod(prices, length, rodLength);

    return 0;
}