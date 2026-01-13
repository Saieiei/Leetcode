//M2 Memoization
//we will use include exclude principle
//we will include only when we reach m>=0 and n>=0
//bc is if index >=size then return 0
//now to do this we have to convert these strings in the form of vectors
    //for now we will use vector<pair<int, int>> //0s and //1s
class Solution {
public:

    void convertion(vector<pair<int, int>>& NumStr, vector<string>& strs){
        for(string& str: strs){
            int ones = 0;
            int zeros = 0;
            for(char ch: str){
                if(ch == '0') zeros++;
                else ones++;
            }
            NumStr.push_back({zeros, ones});
        }

    }
    int recursionMemo(vector<pair<int, int>>& NumStr, int i, int m, int n, vector<vector<vector<int>>>& dp){
        //bc
        if(i >= NumStr.size()) return 0;
        if(dp[i][m][n] != -1) return dp[i][m][n];

        int ones = NumStr[i].second;
        int zeros = NumStr[i].first;
        int include = 0, exclude = 0;
        if(m - zeros >= 0 && n - ones >= 0){
            include = 1 + recursionMemo(NumStr, i + 1, m - zeros, n - ones, dp);
        }
        exclude = recursionMemo(NumStr, i + 1, m, n, dp);

        dp[i][m][n] =  max(include, exclude);
        return dp[i][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>>NumStr;
        convertion(NumStr, strs);
        vector<vector<vector<int>>>dp(NumStr.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        int i = 0; //index
        return recursionMemo(NumStr, i, m, n, dp);
        
    }
};