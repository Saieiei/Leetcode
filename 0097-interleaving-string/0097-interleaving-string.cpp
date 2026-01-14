//M2 Memoization
//not intuitive rather typical
//we will start from 1 string and keep going until we r not able to
//then proceed with the next string and keep going
//we will have to stop when all 3 pointers come to an end
class Solution {
public:
    int recursionMemo(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<vector<int>>>& dp){
        //bc, if we have reached the end of all strings, then it was possible
        if(i == s1.size() && j == s2.size() && k == s3.size()) return 1;
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool flag = false; //this flag part was not intuitive
        if(i < s1.size() && s1[i] == s3[k]){
            flag = flag || recursionMemo(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            flag = flag || recursionMemo(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        dp[i][j][k] =  flag;
        return dp[i][j][k];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i = 0, j = 0, k = 0;
        vector<vector<vector<int>>>dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, - 1)));
        return recursionMemo(s1, s2, s3, i, j, k, dp);
    }
};