class Solution {
private:

    int solveTabulation(vector<int> days, vector<int> costs)
    {
        int n = days.size()-1;
        vector<int> dp(n+2, -1);
        dp[n+1]=0;

        for(int i=n;i>=0;i--)
        {
            //1day
            int cost1 = costs[0] + dp[i+1];

            //7days
            int endDayof7=days[i] + 7 - 1;
            int currDayfor7 = i;
            while(currDayfor7<days.size() && days[currDayfor7] <= endDayof7)
                currDayfor7++;
            int cost7=costs[1] + dp[currDayfor7];

            //30days
            int endDayof30=days[i] + 30 - 1;
            int currDayfor30=i;
            while(currDayfor30<days.size() && days[currDayfor30] <= endDayof30)
                currDayfor30++;
            int cost30=costs[2] + dp[currDayfor30];

            dp[i] = min(cost1, min(cost7, cost30));
        }

        return dp[0];
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int ans = solveTabulation(days, costs);
        return ans;
    }
};