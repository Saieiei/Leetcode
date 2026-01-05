//M2 Memoization
//but bottom up
class Solution {
public:

    int recursionTabu(vector<int>& nums, int start, int end, vector<vector<int>>& dp){
        //bc
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MIN;
        for(int i = start; i <= end; i++){ //since we r coming from bottom up we will have to do nums[start-1]*nums[i]*nums[end+1] 
        //and not nums[i - 1] * nums[i] * nums[i + 1]
            ans = max(ans, (nums[start-1]*nums[i]*nums[end+1] + recursionTabu(nums, start, i-1, dp) + recursionTabu(nums, i+1, end, dp)));
            dp[start][end] = ans;
        }

        return ans;
    }
    int maxCoins(vector<int>& nums) {
        //before and after insert 1 in the array
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int start = 1, end = nums.size() - 2;
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        return recursionTabu(nums, start, end, dp);
    }
};