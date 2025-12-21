//M2 recursion + Memoisation
//i still dont know how it all works
class Solution {
public:
    int recursionMemo(vector<int>& coins, int amount, vector<int>& dp){
        //basecase
        //4. check if its there in dp
        if(amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];

        //only if there is a chnage we will take it, and less amount of coins 
        int mini = INT_MAX; 

        for(int i=0; i<coins.size(); i++){
            //1st check if the amount > coin, then sub
            if(coins[i] <= amount){
                int res = recursionMemo(coins, amount - coins[i], dp);
                if(res != INT_MAX) mini = min(mini, 1 + res); //used up 1 coin
            }
        }
        //3. update the dp
        dp[amount] = mini;
        return mini;     
    }

    int coinChange(vector<int>& coins, int amount){

        //1. create the dp
        int n = amount;
        vector<int>dp(n+1, -1);

        //2. pass and update the dp
        int ans = recursionMemo(coins, amount, dp);
        if(ans == INT_MAX) return -1; //no possible outcomes
        else return ans;

        
    }
};