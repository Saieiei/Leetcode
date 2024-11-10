class Solution {
public:
//O(n*m) time complexity
//O(n*m) space complexity
    int recursion_plus_memorization_method(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0; // No common subsequence

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + recursion_plus_memorization_method(s1, s2, i-1, j-1, dp);
        else 
            return dp[i][j]= max(recursion_plus_memorization_method(s1, s2, i-1, j, dp), recursion_plus_memorization_method(s1, s2, i, j-1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
    int n = text1.length();
    int m = text2.length();
    vector<vector<int>>dp (n, vector<int>(m, -1));

    // Start with the last valid indices: n-1 and m-1
    int ans = recursion_plus_memorization_method(text1, text2, n-1, m-1, dp);
    return ans;
    }
};