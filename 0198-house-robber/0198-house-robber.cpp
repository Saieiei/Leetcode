class Solution {
public:
    int recursion(vector<int>& nums, int index, const int n, vector<int>& dp){
        //bc
        if(index >= n){
            return 0;
        }
        //return if already found
        if(dp[index] != -1){
            return dp[index];
        }
        //we have 2 options, either include the house and follow the rest
        //else exclude the house and follow the rest
        //include
        int include = nums[index] + recursion(nums, index+2, n, dp);
        //exclude
        int exclude = 0 + recursion(nums, index+1, n, dp);
        //returning dp
        dp[index] = max(include, exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //Memoization (check if already found, returning dp)
        //include exclude principal

        int index = 0;
        vector<int>dp(n+5, -1);
        return recursion(nums, index, n, dp);
    }
};