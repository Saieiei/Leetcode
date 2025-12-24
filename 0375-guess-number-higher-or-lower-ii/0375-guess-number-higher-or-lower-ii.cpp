//M2 Memoization
//it is somewhat related to include/exclude principal
//The Idea: if we get into the worst path, we can get to know how much amount is required to burn (max)
//if the number we have selected is not the ans, then the posibility of that number lies between [start x-1] and [x+1, end]
//we will be going into each of these ranges using recursion
//add up the false number as we keep going
class Solution {
public:

    int recursionMemo(int start, int end, vector<vector<int>>& dp){
        //3. basecase and check if its there in dp
        if(start >= end) return 0; //only 1 element left, that is the ans, no need to add anything
        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        //recursion
        for(int i=start; i<=end; i++)
        {
            int LowerBound = recursionMemo(start, i-1, dp);
            int UpperBound = recursionMemo(i+1, end, dp);

            int cost = i + max(LowerBound, UpperBound);
            ans = min(ans, cost);
            //ans = min(ans, i + max(recursion(start, i-1), recursion(i+1, end)));
        }
        //2. store and update the dp
        dp[start][end] = ans;
        return ans;
    }

    int getMoneyAmount(int n) {
        //1. create DP vector<vector<int>> dp
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return recursionMemo(1, n, dp);
    }
};