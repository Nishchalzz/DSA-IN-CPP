#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

int largetSubWith0Sum(vector<int> arr){

    unordered_map<int, int> m;
    int maxLen = 0;
    int sum = 0;

    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(!m.count(sum)){
            m[sum] = i;
        }else{
            maxLen = max(maxLen, i-m[sum]);
        }
    }

    return maxLen;

}


int main(){

    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
    
    cout<<largetSubWith0Sum(arr);


    return 0;
}