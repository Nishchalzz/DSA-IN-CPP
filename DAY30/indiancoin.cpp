#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getcoinchange(vector<int> coins, int v){
    int ans = 0;
    for(int i=coins.size()-1; i>=0 && v>0;i--){
        if(v>coins[i]){
            ans += v/coins[i];
            v = v%coins[i];
        }
    }
    return ans;
}

int main(){

    vector<int> coins = {1,2,5,10,50,100,500,1000,2000};
    int v = 1099;

    cout<<getcoinchange(coins, v);

    return 0;
}