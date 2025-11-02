#include<iostream>
using namespace std;

bool containsDuplicate(int *nums,int n) {
      
      for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(nums[i]==nums[j])
                return true;
        }
      }
      return false;
}

// bool containsDuplicate(vector<int>& nums) {
//      sort(nums.begin(), nums.end());
//      for(int i=1; i<nums.size(); i++) {
//          if(nums[i-1] == nums[i]) {
//              return true;
//          }
//      }
//      return false;
// }



int main(){
    int nums[5]={1,5,2,3,5};
    int n = sizeof(nums)/sizeof(int);  
    cout<<containsDuplicate(nums,n);
    return 0;
}