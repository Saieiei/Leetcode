//M2 Memoization
//not intuitive
//its not include, exclude
//2 pointers, i->s, j->t
//if both same then move both by1
//if not same move only i by 1
class Solution {
public:
    int recursionMemo(string& s, string& t, int i, int j, vector<vector<int>>& dp){
        //bc, this order is imp
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]){ //same
            ans = ans + recursionMemo(s, t, i + 1, j + 1, dp);
        }//if not same
        ans = ans + recursionMemo(s, t, i + 1, j, dp);

        dp[i][j] = ans;
        return ans;
    }
    int numDistinct(string s, string t) {
        int i = 0, j = 0;
        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return recursionMemo(s, t, i, j, dp);
    }
};