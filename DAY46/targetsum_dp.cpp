#include<iostream>
#include<vector>
using namespace std;

bool targetSum(vector<int> nums, int w){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int currwt = nums[i-1];

            if(currwt<=j){
                dp[i][j] = max(currwt+dp[i-1][j-currwt],dp[i-1][j]);

            }else{
                //exclude
                dp[i][j] = dp[i-1][j];
            }

        }
    }

    return dp[n][w]==w;

}


int main(){
    vector<int> nums = {4,2,7,1,3};
    int target = 7;
    cout<<targetSum(nums,target);

    return 0;
}