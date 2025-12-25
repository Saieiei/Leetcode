//M2 Memoization
//the idea is that if they match then move th eindex ahead by 1 fot both
//else we have to move either 1 cuz there is a posibility
    //now we have to move the index which was not moved before
//consider this test case string A = xyzabc, B = abcxyz, there r 2 possibolities, "abc" and "xyz"
//u will get "abc" if u move the A string index and u will get "xyz" if u move the B string index
//we will use recursion for the upcoming comparison
//make sure to take the max of the recursions
class Solution {
public:

    int recursion(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp){
        //3.bc check if its there in dp
        if(index1 >= text1.size()) return 0;
        if(index2 >= text2.size()) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];
        int ans = 0;

        if(text1[index1] == text2[index2]){
            ans = 1 + recursion(text1, text2, index1+1, index2+1, dp);
        }
        else{
            int pattern1 = recursion(text1, text2, index1, index2+1, dp);
            int pattern2 = recursion(text1, text2, index1+1, index2, dp);
            ans = 0 + max(pattern1, pattern2);
        }
        //2. store the ans in dp
        dp[index1][index2] = ans;
        return ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        int index1=0, index2=0;
        //1. create dp
        vector<vector<int>>dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        return recursion(text1, text2, index1, index2, dp);
    }
};