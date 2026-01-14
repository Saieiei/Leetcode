//M1 Memoization
//we will use include exclude principle
//we cannot exclude the negatives all directly cuz of some cases
//it makes sense to sort them up as it helps in multiplication
class Solution {
public:
    int recursionMemo(vector<int>& satisfaction, int indx, int time, vector<vector<int>>& dp){
        //bc
        if(indx >= satisfaction.size()) return 0;
        if(dp[indx][time] != -1) return dp[indx][time];

        int include = satisfaction[indx] * time + recursionMemo(satisfaction, indx + 1, time + 1, dp);
        //If you exclude a dish, you do not spend a time slot on it. So time must stay the same.
        int exclude = recursionMemo(satisfaction, indx + 1, time, dp); 

        dp[indx][time] =  max(include, exclude);
        return dp[indx][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int time = 1, indx = 0;
        vector<vector<int>>dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, - 1));
        return recursionMemo(satisfaction, indx, time, dp);
    }
};