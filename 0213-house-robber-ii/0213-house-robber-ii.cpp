//M3 Tabulation
//this same as the prev 1, just that its in circle so we have 2 possibilities to opeate, then take max of these 2
class Solution {
public:
//we will solve this using recussion but we will get TLE

    int solveTabu(vector<int>& nums, int s, int e)
    {

        vector<int>dp(nums.size() + 2, 0);
        dp[e+1]  = 0;
        
        for(int i = e; i >= s; i--){
            //calculations
            //recurssion
            int option1=(nums[i]+dp[i+2]);
            int option2=(0+dp[i+1]);
            int finalAns=max(option1, option2);
            dp[i] = finalAns;
        }
        return dp[s];
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        //corner cases
        if(n==1) return nums[0];
        //lets think that there r 2 worlds
            //in 1st world robber robs the 1st house and hence wont be able to access the last house
            //hence we r ablee to set the range (starting->0 and ending point->n-2)
            int option1=solveTabu(nums, 0, n-2);
            //in the 2nd world robber robs the 2nd house and hence will be able to access the last house
            //hence we r ablee to set the range (starting->1 and ending point->n-1)
            int option2=solveTabu(nums, 1, n-1);
        int ans=max(option1, option2);
        return ans;
    }
};