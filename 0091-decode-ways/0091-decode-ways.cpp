//M2 Memoization
//either consume 1 char or 2 chars
//even an empty string is considered (i==n)
class Solution {
public:
    int recursion(string& s, int indx, vector<int>& dp){
        //bc
        if(indx == s.size()) return 1; //empty
        if(s[indx] == '0') return 0; //single
        if(dp[indx] != -1) return dp[indx];

        int ways = 0;
        //op1
        ways = recursion(s, indx + 1, dp); //not 1 + r
        //op2
        if(indx + 1 < s.size()){
            int decoded  = (s[indx] - '0')*10 + (s[indx + 1] - '0');
            if(decoded >= 10 && decoded <= 26 ) 
                ways += recursion(s, indx + 2, dp);  //not 1 + r
        }
        dp[indx] = ways;
        return ways;
    }
    int numDecodings(string s) {
        int indx = 0;
        vector<int>dp(s.size() + 1, -1);
        return recursion(s, indx, dp);
        
    }
};