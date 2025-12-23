//M2 Memoization
//we will solve this using include/exclude method
//we will divide the sum in half(target) and include means sub from the target until we get 0
class Solution {
public:

    bool recursionMemo(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        int n = nums.size();
        //basecase
        if(index >= n) return 0;
        if(target < 0) return 0;
        if(target == 0) return 1;
        //3. check if its there in dp
        if(dp[index][target] != -1) return dp[index][target];

        int include = recursionMemo(nums, index+1, target - nums[index], dp);
        int exclude = recursionMemo(nums, index+1, target, dp);

        //2. store an update the dp
        dp[index][target] = (include || exclude);
        return dp[index][target];
    }

    bool canPartition(vector<int>& nums) {
        int index = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0); //add up all the ele in sum
        if(sum & 1) return 0; //bitwise, if 1 then odd else 0
        else{
            int target = sum >> 1; //divide it by 2
            //1. create and pass dp
            vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1)); //nums.size() = row, target = col
            return recursionMemo(nums, index, target, dp);
        }
    }
};