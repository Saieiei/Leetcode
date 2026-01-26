//M3 Tabulation
//we have 2 options
//return the sum of the options
class Solution {
public:
    int recursionTabu(int n){
        vector<int>dp(n + 1, 0);
        //bc
        //if(n == 0) return 1; //do nothing
        dp[0] = 1;
        //if(dp[n] != -1) return dp[n];
        for(int i = 1; i <= n; i++){
            int ways = 0;
            //op1
            ways = dp[i-1];
            //op2
            if (i >= 2) ways += dp[i - 2];
            //return sum of options op1 + op2 (we already do it in ways)
            dp[i] = ways; 
        } 
        return dp[n];
    }
    int climbStairs(int n) {
        return recursionTabu(n);
    }
};