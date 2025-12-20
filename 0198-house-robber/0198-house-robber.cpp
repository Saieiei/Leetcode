//M2
//1st we will try to solve this using recursion+Memo
//we will solve it using include and exclude method
class Solution {
public:

    int solveUsingRecurssionTabu(vector<int>& nums, int index){
        //basecase and create dp
        vector<int>dp(nums.size()+2, 0);
        //if(index >= nums.size()) return 0;
        dp[nums.size()] = 0; 

        //bottom up and convertion
        for(int i=nums.size()-1; i>=0; i--){
            int include = nums[i] + dp[i+2];
            int exclude = 0 + dp[i+1];
            dp[i] = max(include, exclude);
        }
        
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int index=0;
        return solveUsingRecurssionTabu(nums, index);
    }
};