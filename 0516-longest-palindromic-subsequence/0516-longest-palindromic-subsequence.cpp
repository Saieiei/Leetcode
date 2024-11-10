class Solution {
public:
    ////O(2^n) time complexity (O(2^n) > O(n^2)) TLE 61 / 86 testcases passed
    ////O(n) space complexity
    //int recurssion_method(string& s, int low, int high)
    //{
    //    //if only 1 character in the string
    //    if(low == high ) return 1;
    //    //if only 2 characters in the string
    //    if(s[low] == s[high] && low+1 == high) return 2;
//
    //    //if last character matches the first character
    //    if(s[low] == s[high]) return recurssion_method(s, low+1, high-1) + 2;
    //    //if last character does not match the first character
    //    else return max(recurssion_method(s, low+1, high), recurssion_method(s, low, high-1));
    //}

    int recursion_method(string& s1, string& s2, int i, int j, vector<vector<int>>& dp)
    {
        if(i < 0 || j < 0) return 0; // No common subsequence

        if(dp[i][j] != -1) return dp[i][j]; //return if u have the value
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + recursion_method(s1, s2, i-1, j-1, dp);
        else 
            return dp[i][j]= max(recursion_method(s1, s2, i-1, j, dp), recursion_method(s1, s2, i, j-1, dp));
    }
    int longestPalindromeSubseq(string s1){
        //int low = 0;
        //int high = s.length();
        //return recurssion_method(s, low, high);

        //recurssion+memoization method
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp (n, vector<int>(m, -1));

        // Start with the last valid indices: n-1 and m-1
        int ans = recursion_method(s1, s2, n-1, m-1, dp);
        return ans;
    }
};


