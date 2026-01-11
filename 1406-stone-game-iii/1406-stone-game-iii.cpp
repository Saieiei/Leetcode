//M2 Memoization
//the idea is we will play on diffeence
    //if a-b>0 Alice wins and so on
//so we will try to make alice win
//we will try to return the max of the ans of the diff (solution is not intuitive)
//since we have a choice of 1st 3 eleme, we will use for loop on that
class Solution {
public:
    int recursionMemo(vector<int>& stoneValue, int idx, vector<int>&dp){
        //bc
        if(idx >= stoneValue.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int ans = INT_MIN;
        int total = 0;
        for(int x = 1; x <= 3; x++){
            if(idx + x - 1 >= stoneValue.size()) break;
            total = total + stoneValue[idx + x -1];
            ans = max(ans, total - recursionMemo(stoneValue, idx + x, dp));
        }
        dp[idx] = ans;
        return ans;
        
    } 
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int>dp(stoneValue.size()+1, -1);
        int ans = recursionMemo(stoneValue, 0, dp);
        if(ans > 0) return "Alice";
        if(ans < 0) return "Bob";
        else return "Tie";
    }
};