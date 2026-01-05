//M3 Tabulation
//but bottom up
class Solution {
public:

    int recursionTabu(vector<int>& nums, int start, int end){
        //bc
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), 0)); //dont have to do +1 idk y
        int n = nums.size();

        for(int start = n-2; start >= 1; start --){ //end should be 1->n; but the base case is end>start return 0; so end = start
            for(int end = start; end <= n-2; end++){
               int ans = INT_MIN;
                for(int i = start; i <= end; i++){ //since we r coming from bottom up we will have to do nums[start-1]*nums[i]*nums[end+1] 
                //and not nums[i - 1] * nums[i] * nums[i + 1]
                    ans = max(ans, (nums[start-1]*nums[i]*nums[end+1] + dp[start][i-1] + dp[i+1][end]));
                    dp[start][end] = ans;
                } 
            }
        }
        return dp[1][n-2]; //not n-2
    }
    int maxCoins(vector<int>& nums) {
        //before and after insert 1 in the array
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int start = 1, end = nums.size() - 2;
        vector<vector<int>>dp(nums.size(), vector<int>(nums.size(), -1));
        return recursionTabu(nums, start, end);
    }
};