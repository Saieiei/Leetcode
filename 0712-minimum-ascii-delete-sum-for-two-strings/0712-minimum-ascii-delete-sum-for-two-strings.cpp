//M3 Tabulation
//not inuitive rather Typical
//to solve this we will either remove 1 char from left side or right side
//if both r same just move both of them ahead
//while removing either left side or right side, add up the cost
    //then leave the rest to recursion
//if 1 string is empty and another is not, then add up all that cost (BC)
class Solution {
public:
    int recursionTabu(string& s1, string& s2, int i, int j){
        //if both empty nothign to do
        vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, 0)); 
        //bc
        //if(dp[i][j] != -1) return dp[i][j];
        //if(i >= s1.size() || j >= s2.size()){
        //    for(int x = j; x <= s2.size() - 1; x++) cost += s2[x];
        //    for(int x = i; x <= s1.size() - 1; x++) cost += s1[x];
        //    return cost;
        //}
        for(int i = s1.size() - 1; i >= 0; i--) 
            dp[i][s2.size()] = s1[i] + dp[i + 1][s2.size()];
        for(int i = s2.size() - 1; i >= 0; i--) 
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i + 1];

        for(int I = s1.size() - 1; I >= 0; I--){
            for(int J = s2.size() - 1; J >= 0; J--){
                int cost = 0;
                if(s1[I] == s2[J]){
                cost = dp[I + 1][J + 1];
                }
                else{
                    int cost1 = s1[I] + dp[I + 1][J];
                    int cost2 = s2[J] + dp[I][J + 1];
                    cost = min(cost1, cost2);
                }
                dp[I][J] = cost;
            }
        }
        return dp[0][0];
    }
    int minimumDeleteSum(string s1, string s2) {
        int i = 0, j = 0;;
        return recursionTabu(s1, s2, i, j);
    }
};