//M2
//1st we will try to solve this using recursion+Memo
//we will solve it using include and exclude method
class Solution {
public:

    int solveUsingRecurssionMemo(vector<int>& nums, int index, vector<int>& dp){
        //basecase and check if the dp value is present
        if(index >= nums.size()) return 0;
        if(dp[index] != -1) return dp[index];

        //recursion
        int include = nums[index] + solveUsingRecurssionMemo(nums, index+2, dp);
        int exclude = 0 + solveUsingRecurssionMemo(nums, index+1, dp);

        //store the value in dp and then return
        dp[index] =  max(include, exclude);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        int index=0;
        vector<int>dp(nums.size()+1, -1);
        return solveUsingRecurssionMemo(nums, index, dp);
    }
};