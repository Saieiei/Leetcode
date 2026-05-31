class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //kadane algo N
        int maxProfit = 0;
        int minPrice = prices[0];
        for(int i=0; i<n; i++){
            minPrice = min(minPrice, prices[i]);
            int currProfit =  prices[i] - minPrice;
            maxProfit = max(maxProfit, currProfit);
        }
        return  maxProfit;
    }
};