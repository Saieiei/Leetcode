//M2 Memoization
//N^N
//we will try to solve for 1 perfect sqaure that is 1
//then we will try to find all the possible combinations using while loop
//the end of the while loop should be sqrt(n) because its square will exceed the value of n
//with the base case we will have to return 1, because of the recursion, so in the final ans we will sub 1
class Solution {
public:
    int recursionMemo(int n, vector<int>& dp){
        //bc
        if(n == 0) return 1; //this is possible
        if(n < 0) return 0; //we cannot accept such a solution
        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int end = sqrt(n);
        for(int i = 1; i <= end; i++){
            int squareValue = i*i;
            int OtherSquareValue = 1 + recursionMemo(n-squareValue, dp);
            ans = min(ans, OtherSquareValue);
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1, -1);
        int ans = recursionMemo(n, dp) -1;
        return ans;
    }
};