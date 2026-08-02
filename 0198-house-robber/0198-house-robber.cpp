class Solution {
public:
    int recursion(vector<int>& nums, int index, const int n){
        //move dp inside, do not intialize this to -1
        vector<int> dp(n+5, 0);
        //bc, but anyways, we have it defined already
        dp[n] = 0;
        //create the loop
        for(int index = n-1; index>=0; index--){
            //we have 2 options, either include the house and follow the rest
            //else exclude the house and follow the rest
            //include
            int include = nums[index] + dp[index+2];
            //exclude
            int exclude = 0 + dp[index+1];
            //returning dp
            dp[index] = max(include, exclude);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //Tabulation 
        //(move dp inside, change BC, create a loop in the oppo dir, remove recursion, return opo extreme index)
        //include exclude principal

        int index = 0;
        return recursion(nums, index, n);
    }
};