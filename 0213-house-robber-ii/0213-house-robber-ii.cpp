class Solution {
public:
//we will solve this using recussion but we will get TLE

    int solve(vector<int>& nums, int s, int e, vector<int>& dp)
    {
        //base case
        if(s>e) return 0;
        if(dp[s] != -1) return dp[s];

        //calculations
        //recurssion
        int option1=(nums[s]+solve(nums, s+2, e, dp));
        int option2=(0+solve(nums, s+1, e, dp));
        int finalAns=max(option1, option2);
        dp[s] = finalAns;
        return dp[s];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        //corner cases
        if(n==1) return nums[0];
        //lets think that there r 2 worlds
            //in 1st world robber robs the 1st house and hence wont be able to access the last house
            //hence we r ablee to set the range (starting->0 and ending point->n-2)
            vector<int>dp(nums.size(), -1);
            int option1=solve(nums, 0, n-2, dp);
            //in the 2nd world robber robs the 2nd house and hence will be able to access the last house
            //hence we r ablee to set the range (starting->1 and ending point->n-1)
            dp.assign(nums.size(), -1);
            int option2=solve(nums, 1, n-1, dp);
        int ans=max(option1, option2);
        return ans;
    }
};