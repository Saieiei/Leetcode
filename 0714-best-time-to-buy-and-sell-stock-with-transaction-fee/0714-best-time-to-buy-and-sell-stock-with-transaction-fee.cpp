//M1 recursion
//this is same as https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/
//just that when ur selling, u should sub the profit with trasaction fee
class Solution {
public:
    int recursion(vector<int>& prices, int index, bool buy, int &fee){
        //bc
        if(index >= prices.size()) return 0;
        int maxProfit = INT_MIN;
        

        //we r going to buy
        if(buy){
            int buyProfit = -prices[index] + recursion(prices, index+1, 0, fee); //u cant buy another1 when u bought 1 already
            int holdingBuyProfit = 0 + recursion(prices, index+1, 1, fee); //u can buy 1 when u have nothing to hold
            maxProfit = max(buyProfit, holdingBuyProfit);
        }
        else //we r going to sell
        {
            //after complete trans apply trans fee
            int SellProfit = prices[index] + recursion(prices, index+1, 1, fee) - fee; //u can buy when ur trying to sell,
            int holdingSellProfit = 0 + recursion(prices, index+1, 0, fee); //u cant buy 1 when ur still trying to hold the share instead of selling it
            maxProfit = max(SellProfit, holdingSellProfit);
        }

        return maxProfit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int index = 0, buy = 1;
        return recursion(prices, index, buy, fee);
        
    }
};