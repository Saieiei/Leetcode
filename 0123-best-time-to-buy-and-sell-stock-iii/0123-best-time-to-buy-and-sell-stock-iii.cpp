//M3 Tabulation
//this is same as teh previous1 https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/1872895528/
//just that we have we have limit of max 2 transactions
class Solution {
public:

    int recursionTabu(vector<int>& prices, int index, bool buy, int limits){
        //bc
        vector<vector<vector<int>>>dp(prices.size()+1, vector<vector<int>>(2, vector<int>(2+1, 0)));

        for(int i = prices.size()-1; i>=0; i--){
            for(int j = 0; j <= 1; j++){
                for(int k = 1; k <= 2; k++){
                    int maxProfit = INT_MIN;

                    //we r going to buy
                    if(j){
                        int buyProfit = -prices[i] + dp[i+1][0][k]; //u cant buy another1 when u bought 1 already, we havent sold it yet so can decresse the limit
                        int holdingBuyProfit = 0 + dp[i+1][1][k]; //u can buy 1 when u have nothing to hold
                        maxProfit = max(buyProfit, holdingBuyProfit);
                    }
                    else //we r going to sell
                    {
                        int SellProfit = prices[i] + dp[i+1][1][k-1]; //u can buy when ur trying to sell, we have sold it so we can decrase the limit now
                        int holdingSellProfit = 0 + dp[i+1][0][k]; //u cant buy 1 when ur still trying to hold the share instead of selling it
                        maxProfit = max(SellProfit, holdingSellProfit);
                    }

                    dp[i][j][k] = maxProfit;
                }
            }
        }
        return dp[0][1][2];
    }

    int maxProfit(vector<int>& prices) {
        int index = 0;
        int limits = 3;
        return recursionTabu(prices, index, true, limits);
    }
};