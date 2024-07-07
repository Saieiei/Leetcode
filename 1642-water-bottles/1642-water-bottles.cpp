class Solution {
public:
    int recurssion(int numBottles, int numExchange, int empty, int& anss)
    {
        //base case
        if(numBottles == 0 && empty < numExchange) return anss;
        
        //now we will solve 1 case, recurssion
        if(numBottles > 0)
        {
            anss = anss + numBottles;
            empty = empty + numBottles;
            numBottles = 0;
        }
        //refilling
        if(empty >= numExchange)
        {
            numBottles = empty / numExchange;
            empty = empty % numExchange;
        }
        recurssion(numBottles, numExchange, empty, anss);
        return anss;
    }
    int numWaterBottles(int numBottles, int numExchange) {
        //recurssion
        int anss = 0;
        int empty = 0;
        int ans = recurssion(numBottles, numExchange, empty, anss);
        return ans;
    }
};