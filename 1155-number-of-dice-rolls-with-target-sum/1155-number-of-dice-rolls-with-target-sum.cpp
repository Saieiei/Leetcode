//M2 Memoization
//we will take 1 dice and use all its faces(values)
    //as we keep going we will reduce the target and the no of dices used
class Solution {
public:
    long long int mod = 1000000007; //we use this mod because the q is telling us to use it

    int recursionMemo(int n, int k, int target, vector<vector<long long int>>& dp){
        //3. basecase and check dp
        if(n==0 && target == 0) return 1; //u have no dice left and u have to make 0 sum
        if(n==0 && target != 0) return 0; //u have no dices left and u have to make target
        if(n!=0 && target == 0) return 0; //u have deices left and u have to make sum 0
        if(n<0 || target <0) return 0; 
        if(dp[n][target] != -1) return dp[n][target];

        int ans = 0;
        for(int value=1; value<=k; value++){
            ans = (ans + recursionMemo(n-1, k, target-value, dp)) %mod; //we use mod because the q is telling us
        }

        //2. store the ans in dp
        dp[n][target] = ans;
        return ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        //1. create dp
        vector<vector<long long int>> dp(n+1, vector<long long int>(target+1, -1));
        return recursionMemo(n, k, target, dp);
    }
};