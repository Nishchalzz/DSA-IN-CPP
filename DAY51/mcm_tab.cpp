#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mcmTab(vector<int> arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 1; i < n; i++) {
        dp[i][i] = 0;
    }

    for (int len = 2; len < n; len++) {
        for (int i = 1; i <= n - len; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost1 = dp[i][k];
                int cost2 = dp[k + 1][j];
                int currCost = cost1 + cost2 + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], currCost);
            }
        }
    }

    return dp[1][n - 1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 3};
    cout << mcmTab(arr);
    return 0;
}