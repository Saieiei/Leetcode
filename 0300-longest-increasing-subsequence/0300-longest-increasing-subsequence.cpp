//M2 Recursion + Memoization
//we will solve this using inclusion exclusion logic (take teh max out of the 2)
//we will include only when the ele > subsequence
class Solution {
public:

    int recursionMemo(vector<int>& nums, int prev, int curr, vector<vector<int>>& dp){
        //3. basecase + check if value is already prent in dp
        if(curr >= nums.size()) return 0; //dont add anythign
        if(dp[curr][prev+1] != -1) return dp[curr][prev+1]; //+1 because prev can be -1

        int include = 0;
        //we will only include if prev is -1 (just starting) or when the curr>prev
        if(prev == -1 || nums[curr] > nums[prev]){
            //we move 1 step ahead (curr and prev) and incease the include value by 1
            include = 1 + recursionMemo(nums, curr, curr+1, dp); 
        }
        int exclude = 0 + recursionMemo(nums, prev, curr+1, dp); //we dont update prev, cuz nothign was added

        //2. store the ans in dp
        int ans = max(include, exclude);
        dp[curr][prev+1] = ans;
        return ans;
    }

    int lengthOfLIS(vector<int>& nums) {
        int curr = 0, prev = -1; //represent the index
        //1. create dp
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return recursionMemo(nums, prev, curr, dp);
    }
};