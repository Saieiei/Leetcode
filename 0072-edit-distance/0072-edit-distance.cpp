//M3 Tabulation
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
    int recursionTabu(string& word1, string& word2, int i, int j){
        //1. create dp
        vector<vector<int>>dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        //bc
        for(int i=0; i<=word2.length(); i++){ //insertion
            dp[word1.length()][i] = word2.length()-i;
        }

        for(int i=0; i<=word1.length(); i++){ //deletion
            dp[i][word2.length()] = word1.length()-i;
        }

        //2. for-loop, reversed, copy-paste, rec-func, indexing
        for(int i = word1.length()-1; i>=0; i--){
            for(int j = word2.length()-1; j>=0; j--){
                int ans =0;
                if(word1[i] == word2[j]){ //do nothign, just move forward
                    ans =  dp[i+1][j+1];
                }
                else
                {
                    int inserted = 1 + dp[i][j+1];
                    int deleted =  1 + dp[i+1][j];
                    int replaced = 1 + dp[i+1][j+1];
                    ans = min(replaced, min(inserted, deleted));
                }
                //2. save the results in dp
                dp[i][j] = ans;
            }
        }
        
        //3. return accordingly
        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        //few bc before we proceed with recursion
        if(word1.length() == 0) return word2.length(); //insertion
        if(word2.length() == 0) return word1.length(); //deletion

        int i=0, j = 0;
        
        return recursionTabu(word1, word2, i, j);
    }
};