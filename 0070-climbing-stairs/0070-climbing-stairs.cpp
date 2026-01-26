//M2 Memoization
//we have 2 options
//return the sum of the options
class Solution {
public:
    int recursionMemo(int n, vector<int>& dp){
        //bc
        if(n == 0) return 1; //do nothing
        if(dp[n] != -1) return dp[n];
        int ways = 0;
        //op1
        ways = recursionMemo(n-1, dp);
        //op2
        if (n >= 2) ways += recursionMemo(n - 2, dp);
        //return sum of options op1 + op2 (we already do it in ways)
        dp[n] = ways; 
        return ways;
    }
    int climbStairs(int n) {
        vector<int>dp(n + 1, -1);
        return recursionMemo(n, dp);
    }
};