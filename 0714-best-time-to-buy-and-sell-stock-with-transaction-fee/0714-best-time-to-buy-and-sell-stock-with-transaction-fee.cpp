//M2 Memoization
//this is same as https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
//just that when ur selling, u should sub the profit with trasaction fee when ur selling it (1 complete transaction)
class Solution {
public:
    int recursionMemo(vector<int>& prices, int index, bool buy, vector<vector<int>>& dp, int& fee){
        //bc
        if(index >= prices.size()) return 0;
        if(dp[index][buy] != -1) return dp[index][buy];
        int maxProfit = INT_MIN;
        

        //we r going to buy
        if(buy){
            int buyProfit = -prices[index] + recursionMemo(prices, index+1, 0, dp, fee); //u cant buy another1 when u bought 1 already
            int holdingBuyProfit = 0 + recursionMemo(prices, index+1, 1, dp, fee); //u can buy 1 when u have nothing to hold
            maxProfit = max(buyProfit, holdingBuyProfit);
        }
        else //we r going to sell
        {
            int SellProfit = prices[index] + recursionMemo(prices, index+1, 1, dp, fee) - fee; //u can buy when ur trying to sell
            int holdingSellProfit = 0 + recursionMemo(prices, index+1, 0, dp, fee); //u cant buy 1 when ur still trying to hold the share instead of selling it
            maxProfit = max(SellProfit, holdingSellProfit);
        }

        dp[index][buy] = maxProfit;
        return maxProfit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int index = 0;
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, -1));
        return recursionMemo(prices, index, true, dp, fee);
    }
};