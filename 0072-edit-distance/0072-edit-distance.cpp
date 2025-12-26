//M2 Memoization
//we have 3 operations if the chars dont match
    //if we use insertion(+1), we will move j++;
    //if we use deletion(+1) we will move i++
    //if we use replace(+1) we will do i++ and j++
//now from these operations we have to take the min and return the ans
//if they r the same(+0) then do i++ and j++
//if we reach the end of w2, then we have to delete the remaing words in w1 from w2, so return (w1.length() -i)
//if we reach the end of w1, then we have to insert the remaing words in w1 from w2, so return (w2.length() -j)
class Solution {
public:


    int recursionMemo(string& word1, string& word2, int i, int j, vector<vector<int>>& dp){
        //bc
        if(i>=word1.length()){ //insertion
            return word2.length()-j;
        }
        if(j>=word2.length()){ //deletion
            return word1.length()-i;
        }
        //2. with bc check if its there in dp
        if(dp[i][j] != -1) return dp[i][j];


        int ans =0;
        if(word1[i] == word2[j]){ //do nothign, just move forward
            ans =  recursionMemo(word1, word2, i+1, j+1, dp);
        }
        else
        {
            int inserted = 1 + recursionMemo(word1, word2, i, j+1, dp);
            int deleted =  1 + recursionMemo(word1, word2, i+1, j, dp);
            int replaced = 1 + recursionMemo(word1, word2, i+1, j+1, dp);
            ans = min(replaced, min(inserted, deleted));
        }
        //2. save the results in dp
        dp[i][j] = ans;
        return ans;
    }

    int minDistance(string word1, string word2) {
        //few bc before we proceed with recursion
        if(word1.length() == 0) return word2.length(); //insertion
        if(word2.length() == 0) return word1.length(); //deletion

        int i=0, j = 0;
        //1. create dp
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, -1));
        return recursionMemo(word1, word2, i, j, dp);
    }
};