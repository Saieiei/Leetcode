//M3 Memoization
//not intuitive
//its not include, exclude
//2 pointers, i->s, j->t
//if both same then move both by1
//if not same move only i by 1
class Solution {
public:
    int recursionTabu(string& s, string& t, int i, int j){
        //if(i >= s.size()) return 0;
        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        //if(j >= t.size()) return 1;
        for(int i = 0; i <= s.size(); i++){
            dp[i][t.size()] = 1;
        }

        for(int I = s.size() - 1; I >= 0; I--){
            for(int J = t.size() - 1; J >= 0; J--){
                long long ans = 0;
                if(s[I] == t[J]){ //same
                    ans = ans + dp[I + 1][J + 1];
                }//if not same
                ans = ans + dp[I + 1][J];

                dp[I][J] = ans;
            }
        }
        return dp[0][0];
    }
    int numDistinct(string s, string t) {
        int i = 0, j = 0;
        vector<vector<int>>dp(s.size() + 1, vector<int>(t.size() + 1, -1));
        return recursionTabu(s, t, i, j);
    }
};