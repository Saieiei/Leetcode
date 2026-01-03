//M3 Tabulation
//this is not intuitive
//we have 2 cases, that is to make profit when we buy and sell
//and in each case we can either hold or execute
class Solution {
public:

    int recursionTabu(vector<int>& prices){
        vector<vector<int>>dp(prices.size()+1, vector<int>(2, 0)); //if(index >= prices.size()) return 0;

        for(int i = prices.size()-1; i >=0; i--){
            for(int buy = 0; buy <= 1; buy++){

                int maxProfit = INT_MIN;
                //we r going to buy
                if(buy){
                    int buyProfit = -prices[i] + dp[i + 1][0]; //u cant buy another1 when u bought 1 already
                    int holdingBuyProfit = 0 + dp[i+1][1]; //u can buy 1 when u have nothing to hold
                    maxProfit = max(buyProfit, holdingBuyProfit);
                }
                else //we r going to sell
                {
                    int SellProfit = prices[i] + dp[i + 1][1]; //u can buy when ur trying to sell
                    int holdingSellProfit = 0 + dp[i + 1][0]; //u cant buy 1 when ur still trying to hold the share instead of selling it
                    maxProfit = max(SellProfit, holdingSellProfit);
                }

                dp[i][buy] = maxProfit;
            }
        }

        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int index = 0;
        return recursionTabu(prices);
    }
};