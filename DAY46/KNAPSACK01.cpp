#include<iostream>
#include<vector>
using namespace std;

int knapsackrec(int i, vector<int>& wt, vector<int>& val, int WT){

    if(WT == 0 || i==0){
        return 0;
    }

    int currwt = wt[i-1];
    int currval = val[i-1];

    if(currwt<=WT){
        //include
        int ans1 = knapsackrec(i-1,wt,val,WT-currwt) + currval;

        //exclude
        int ans2 = knapsackrec(i-1,wt,val,WT);

        return max(ans1,ans2);

    }else{
        //exlclude
        return knapsackrec(i-1,wt,val,WT);
    }
}

int knapsackmem(int n, vector<int>& wt, vector<int>& val, int WT,vector<vector<int>>& dp){

    if(WT == 0 || n==0){
        return 0;
    }

    if(dp[n][WT]!=-1){
        return dp[n][WT];
    }

    int currwt = wt[n-1];
    int currval = val[n-1];

    if(currwt<=WT){
        //include
        int ans1 = knapsackmem(n-1,wt,val,WT-currwt,dp) + currval;

        //exclude
        int ans2 = knapsackmem(n-1,wt,val,WT,dp);

        dp[n][WT] = max(ans1,ans2);

    

    }else{
        //exlclude
        dp[n][WT] = knapsackmem(n-1,wt,val,WT,dp);

    }

    return dp[n][WT];
}

int knapsacktab(int n, vector<int> wt, vector<int> val, int w){

    vector<vector<int>> dp(n+1, vector<int>(w+1,0));

    for(int i=1;i<n+1;i++){
        for(int j=1;j<w+1;j++){
            int currval = val[i-1];
            int currwt = wt[i-1];

            if(currwt<=j){
                dp[i][j] = max(currval+dp[i-1][j-currwt],dp[i-1][j]);
            }else{
                //exclue
                dp[i][j] = dp[i-1][j];
            }


        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<w+1;j++){
            cout<<dp[i][j]<<"     " ;   
        }
        cout<<endl;
    }

    return dp[n][w];

}

int main(){

    vector<int> val = {15,14,10,45,30};
    vector<int> wt = {2,5,1,3,4};
    int n = 5;
    int w = 7;

    vector<vector<int>> dp(n+1, vector<int>(w+1, -1));

    cout<<knapsacktab(5,wt,val,7);

    // cout<<knapsackrec(5,wt,val,7);

    // cout<<knapsackmem(n,wt,val,w,dp);

    return 0;
}