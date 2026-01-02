//M2 Memoization
//This idea with base case is not intuitive
//we will compute each cost separately and take out min
class Solution {
public:

    int recursionMemo(vector<int>& days, vector<int>& costs, int i, vector<int>& dp){
        //bc
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int cost1 = 0;
        cost1 = costs[0] + recursionMemo(days, costs, i + 1, dp);

        int cost2 = 0;
        int endDay = days[i] + 7 - 1;
        int j = i;
        while(j < days.size() && days[j] <= endDay){
            j++;
        }
        cost2 = costs[1] + recursionMemo(days, costs, j, dp);

        int cost3 = 0;
        endDay = days[i] + 30 - 1;
        j = i;
        while(j < days.size() && days[j] <= endDay){
            j++;
        }
        cost3 = costs[2] + recursionMemo(days, costs, j, dp);

        dp[i] = min(cost1, min(cost2, cost3));
        return dp[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i = 0; //days travelled/indx of days
        vector<int>dp(days.size() + 1, -1);
        return recursionMemo(days, costs, i, dp);
        
    }
};