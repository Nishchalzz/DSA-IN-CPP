#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int mcmMem(vector<int> arr, int i, int j,vector<vector<int>> &dp){
    if(dp[i][j]!=-1)
        return dp[i][j];

    if(i==j)
        return 0;

    int ans = INT_MAX;

    for(int k=i;k<j;k++){
        int cost1 = mcmMem(arr, i, k,dp);
        int cost2 = mcmMem(arr, k+1, j,dp);
        int totcost = cost1 + cost2 + (arr[i-1]*arr[k]*arr[j]);

        ans = min(totcost, ans);
        dp[i][j] = ans;
    }

    return ans;
}


int main(){
    vector<int> arr = {1,2,3,4,3};
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout<<mcmMem(arr, 1, n-1,dp);

    return 0;
}