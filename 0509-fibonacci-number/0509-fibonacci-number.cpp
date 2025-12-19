//we will be doing it using recustion 1st and then DP(memoization)
class Solution {
public:

    int recursionFibTabulation(int n){
        //instead of basecase we directly tabulate
        vector<int> dp(n+1, -1); //always keep 1 extra
        if(n==0 || n==1) return n;
        dp[0]=0; dp[1]=1;

        //bottom up approach
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int fib(int n) {
        //for DP
        return recursionFibTabulation(n);
    }
};