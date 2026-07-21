class Solution {
public:
    int rob1(int n, vector<int> nums){
        int prev = nums[0];
        int prev2 = 0;



        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i-2>=0)
                take += prev2;

            int nottake = prev;

            int curri = max(take,nottake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {

        if(nums.size() == 1)
            return nums[0];
        vector<int> temp(nums.begin(),nums.end()-1);
        vector<int> temp2(nums.begin()+1,nums.end());
        int n = nums.size();

        return max(rob1(n-1, temp),rob1(n-1,temp2));

    }
};