//we will be doing it using recustion 1st and then DP(memoization)
class Solution {
public:

    int recursionFib(int n, vector<int>& dp){
        //basecase
        if(n==0 || n==1) return n;
        //check if we have the result usinf dp
        if(dp[n] != -1){
            return dp[n];
        }

        //recursion
        int ans = recursionFib(n-1, dp) + recursionFib(n-2, dp);
        //store the ans in dp
        dp[n] = ans;
        return ans;
    }

    int fib(int n) {
        //for DP
        vector<int> dp(100, -1);
        int ans = recursionFib(n, dp);
        return ans;
    }
};