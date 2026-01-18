//M2 Memoization
//not intuitive rather typical
//take up every char to the word and check in dict
//return the ans with flag
//use or in the flag for continued searches (aaa, aaaa -> aaaaa)
//reset the word serch with recursion
class Solution {
public:
    bool check (string& word, vector<string>& wordDict){
        for(string i: wordDict){
            if(word == i) return true;
        }
        return false;
    }

    bool recursionMemo(string& s, vector<string>& wordDict, int indx, vector<int>& dp){
        //bc
        if(indx == s.size()) return true;
        if(dp[indx] != -1) return dp[indx];

        string word = "";
        bool flag = false;
        for(int i = indx; i <= s.size() - 1; i++){ //start from indx and not 0
            word += s[i];
            if(check(word, wordDict))
                flag = flag || recursionMemo(s, wordDict, i + 1, dp); //dont return immediately
                //we need to explore other options as well
        }
        dp[indx] = flag;
        return flag;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int indx = 0;
        vector<int>dp(s.size() + 1, -1);
        return recursionMemo(s, wordDict, indx, dp);
    }
};