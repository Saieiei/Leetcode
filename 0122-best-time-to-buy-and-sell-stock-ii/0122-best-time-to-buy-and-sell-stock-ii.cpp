//M2 Memoization
//this is not intuitive
//we have 2 cases, that is to make profit when we buy and sell
//and in each case we can either hold or execute
class Solution {
public:

    int recursionMemo(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp){
        //bc
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int maxProfit = INT_MIN;
        

        //we r going to buy
        if(buy){
            int buyProfit = -prices[index] + recursionMemo(prices, index+1, 0, dp); //u cant buy another1 when u bought 1 already
            int holdingBuyProfit = 0 + recursionMemo(prices, index+1, 1, dp); //u can buy 1 when u have nothing to hold
            maxProfit = max(buyProfit, holdingBuyProfit);
        }
        else //we r going to sell
        {
            int SellProfit = prices[index] + recursionMemo(prices, index+1, 1, dp); //u can buy when ur trying to sell
            int holdingSellProfit = 0 + recursionMemo(prices, index+1, 0, dp); //u cant buy 1 when ur still trying to hold the share instead of selling it
            maxProfit = max(SellProfit, holdingSellProfit);
        }

        dp[index][buy] = maxProfit;
        return maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        int index = 0;
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return recursionMemo(prices, index, true, dp);
    }
};