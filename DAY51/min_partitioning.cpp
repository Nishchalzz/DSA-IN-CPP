#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getMinDif(vector<int> arr){

    int n = arr.size();
    int totalSum = 0;

    for(int el:arr){
        totalSum += el;
    }

    int w = totalSum/2;
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(arr[i-1] <= j){
                dp[i][j] = max(arr[i-1]+dp[i-1][j-arr[i-1]], dp[i-1][j]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int cost1 = dp[n][w];
    int cost2 = totalSum-cost1;

    return abs(cost1-cost2);

}

int main() {
    vector<int> arr = {1,2,3};
    cout<<getMinDif(arr);

    return 0;
}