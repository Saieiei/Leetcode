//M3 recursion + Tabulation
//i still dont know how it all works
class Solution {
public:
    int recursionTabu(vector<int>& coins, int amount){
        //1. create dp
        int n = amount;
        vector<int>dp(n+1, INT_MAX); //for each block, it will take INT_MAX amount of ways(not ideal)

        //2. Analyse BC and update the dp
        dp[0] = 0;

        //3. for loop, reversed, copy-paste, replace functions, looping variable
        for(int value=1; value<=amount; value++){
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++){
                //1st check if the amount > coin, then sub
                if(coins[i] <= value){
                    int res = dp[value - coins[i]];
                    if(res != INT_MAX) mini = min(mini, 1 + res); //used up 1 coin
                }
            }
            dp[value] = mini;
        }
        //4. return accordingly
        return dp[amount];     
    }

    int coinChange(vector<int>& coins, int amount){

        int ans = recursionTabu(coins, amount);

        if(ans == INT_MAX) return -1; //no possible outcomes
        else return ans;

        
    }
};