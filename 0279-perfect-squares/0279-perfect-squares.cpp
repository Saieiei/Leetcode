//M3 Tabulation
//N^N
//we will try to solve for 1 perfect sqaure that is 1
//then we will try to find all the possible combinations using while loop
//the end of the while loop should be sqrt(n) because its square will exceed the value of n
//with the base case we will have to return 1, because of the recursion, so in the final ans we will sub 1
class Solution {
public:
    int recursionTabu(int n){
        vector<int>dp(n+1, 0); //if(n < 0) return 0
        //bc
        //if(n == 0) return 1; //this is possible
        dp[0] = 1;
        //if(n < 0) return 0; //we cannot accept such a solution
        //if(dp[n] != -1) return dp[n];

        for(int i = 1; i <= n; i++){
            int ans = INT_MAX;
            int end = sqrt(i); //i
            for(int ii = 1; ii <= end; ii++){ 
                int squareValue = ii*ii;
                int OtherSquareValue = 1 + dp[i-squareValue]; //i
                ans = min(ans, OtherSquareValue);
            }
            dp[i] = ans;
        }
        return dp[n];
    }
    
    int numSquares(int n) {
        int ans = recursionTabu(n) -1;
        return ans;
    }
};