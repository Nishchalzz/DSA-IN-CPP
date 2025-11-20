#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int SubWithSum(vector<int> arr, int k){
    int ans = 0;
    int sum = 0;

    unordered_map<int, int> m; //sum, count
    m[0] = 1;

    for(int j=0;j<arr.size();j++){
        sum += arr[j];

        if(m.count(sum-k)){
            ans += m[sum-k];
        }

        if(!m.count(sum)){
            m[sum] = 1;
        }else{
            m[sum]++;
        }

    }

    return ans;

}


int main(){

    vector<int> arr = {10,2,-2,-20,10};
    int k=-10;
    cout<<SubWithSum(arr, k);


    return 0;
}