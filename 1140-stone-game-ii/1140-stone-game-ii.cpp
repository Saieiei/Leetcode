//not intuitinal, rather tipical
//M2 Memoization
//we will start with i, M, whose turn it is
//1 <= X <= 2M we will use this as for loop
//we will do in turns of alice
//if its alice turn we will start with INT_MIN cuz we have to get its max
    //and if its bob we will start wit INT_MAX cuz we have to get its min
//after getting the total we will keep updating the max
class Solution {
public:
    int recursionMemo(vector<int>& piles, int i, int m, int AliceTurn, vector<vector<vector<int>>>& dp){
        //bc
        if(i >= piles.size()) return 0;
        if(dp[i][m][AliceTurn] != -1) return dp[i][m][AliceTurn];

        int ans = AliceTurn ? INT_MIN : INT_MAX;
        int total = 0;

        for(int x = 1; x <= 2*m; x++){
            if(x+i-1 >= piles.size()) break;// out of bound, not needed
            total  = total + piles[x+i-1];
            if(AliceTurn){
            ans = max(ans, total + recursionMemo(piles, i + x, max(x, m), !AliceTurn, dp));
            }
            else{
                ans = min(ans, recursionMemo(piles, i + x, max(x, m), !AliceTurn, dp)); //dont add it to total
            }
        }
        dp[i][m][AliceTurn] = ans;
        return ans;
    }
    int stoneGameII(vector<int>& piles) {
        int i = 0;
        int AliceTurn = 1;
        int m = 1;
        vector<vector<vector<int>>>dp(piles.size()+1, vector<vector<int>>(piles.size()+1, vector<int>(2, -1)));
        return recursionMemo(piles, i, m, AliceTurn, dp);
    }
};