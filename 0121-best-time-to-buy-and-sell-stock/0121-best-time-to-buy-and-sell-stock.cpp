class Solution {
public:
    void maxProfitRE(vector<int>& prices, int index, int &minPrice, int &maxProfit)
    {
        //base condition
        if(index==prices.size()) return; //gg over
        

        //calculation
        int currentPrice=prices[index];
        if(currentPrice<minPrice)
        {
            minPrice=currentPrice;
        }
        int profit=currentPrice-minPrice;
        if(profit>maxProfit)
        {
            maxProfit=profit;
        }


        //RE
        maxProfitRE(prices, index+1, minPrice, maxProfit);
    }

    int maxProfit(vector<int>& prices) {
        //we will use recurssion for this, week7

        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        //we will not be returning anything as we will make direct chnages into the variable (call by reference)
        maxProfitRE(prices, 0, minPrice, maxProfit);
        return maxProfit;
        
    }
};