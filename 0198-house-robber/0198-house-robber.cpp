//M3
//1st we will try to solve this using recursion+Tabu
//we will solve it using include and exclude method
class Solution {
public:

    int solveUsingRecurssionTabu(vector<int>& nums, int index){
        //basecase and create dp
        int n = nums.size();
        vector<int>dp(n+1, -1);
        //if(index >= nums.size()) return 0;
        dp[n] = 0; 

        //bottom up and convertion
        for(int i=n-1; i>=0; i--){
            
            int temp = 0;
            if(i == n-1) temp = 0; //will go out of bounds or else
            else temp = dp[i+2];

            int include = nums[i] + temp;
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