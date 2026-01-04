//M4 SO
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/1874135977/
//just change 2 to k
class Solution {
public:

    int recursionSO(vector<int>& prices, int index, bool buy, int limits){
        //bc
        vector<vector<vector<int>>>dp(2, vector<vector<int>>(2, vector<int>(limits+1, 0)));

        for(int i = prices.size()-1; i>=0; i--){
            for(int j = 0; j <= 1; j++){
                for(int k = 1; k <= limits; k++){
                    int maxProfit = INT_MIN;

                    //we r going to buy
                    if(j){
                        int buyProfit = -prices[i] + dp[1][0][k]; //u cant buy another1 when u bought 1 already, we havent sold it yet so can decresse the limit
                        int holdingBuyProfit = 0 + dp[1][1][k]; //u can buy 1 when u have nothing to hold
                        maxProfit = max(buyProfit, holdingBuyProfit);
                    }
                    else //we r going to sell
                    {
                        int SellProfit = prices[i] + dp[1][1][k-1]; //u can buy when ur trying to sell, we have sold it so we can decrase the limit now
                        int holdingSellProfit = 0 + dp[1][0][k]; //u cant buy 1 when ur still trying to hold the share instead of selling it
                        maxProfit = max(SellProfit, holdingSellProfit);
                    }

                    dp[0][j][k] = maxProfit;
                }
            }
            //shifting
            dp[1] = dp[0];
        }
        return dp[0][1][limits];
    }

    int maxProfit(int k, vector<int>& prices) {
        int index = 0;
        int limits = k;
        return recursionSO(prices, index, true, limits);
    }
};