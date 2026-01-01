//M3 Memoizzation (Khadanaes Algo)
//we will start from the end
//Idea: should we consider this only elem or add up this eleme with the previous1
//in the end return the max so far found
class Solution {
public:

    int globalMax;

    int recursion(vector<int>& nums, int end, vector<int>& dp){
        //bc
        if(end == 0) return nums[0]; //just return the 1 and only ele
        if(dp[end] != -1) return dp[end];

        int PrevIndxMax = recursion(nums, end-1, dp);
        int currIndxMax = max(nums[end], nums[end] + PrevIndxMax);
        globalMax = max(globalMax, currIndxMax);
        //make sure to return 
        dp[end] = currIndxMax;
        return currIndxMax;
    }

    int maxSubArray(vector<int>& nums) {
        globalMax = nums[0]; //incase we have only ele, this will help
        int n = nums.size()-1;
        vector<int>dp(nums.size(), -1);
        recursion(nums, n, dp);
        return globalMax;
    }
};