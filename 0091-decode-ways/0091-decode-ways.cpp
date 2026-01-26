//M3 Tabulation
//either consume 1 char or 2 chars
//even an empty string is considered (i==n)
class Solution {
public:
    int recursion(string& s, int indx){
        vector<int>dp(s.size() + 1, 0);
        //bc
        //if(indx == s.size()) return 1; //empty
        dp[s.size()] = 1;
        //if(s[indx] == '0') return 0; //single
        //if(dp[indx] != -1) return dp[indx];

        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '0'){ //bc
                dp[i] = 0;
                continue;
            }
            
            int ways = 0;
            //op1
            ways = dp[i + 1]; //not 1 + r
            //op2
            if(i + 1 < s.size()){
                int decoded  = (s[i] - '0')*10 + (s[i + 1] - '0');
                if(decoded >= 10 && decoded <= 26 ) 
                    ways += dp[i + 2];  //not 1 + r
            }
            dp[i] = ways;
        }
        return dp[0];
    }
    int numDecodings(string s) {
        int indx = 0;
        return recursion(s, indx);
        
    }
};