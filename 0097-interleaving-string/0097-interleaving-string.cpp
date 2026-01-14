//M3 Tabulation
//not intuitive rather typical
//we will start from 1 string and keep going until we r not able to
//then proceed with the next string and keep going
//we will have to stop when all 3 pointers come to an end
class Solution {
public:
    int recursionTabu(string& s1, string& s2, string& s3, int i, int j, int k){
        //initialise all to 0, if we reach the bc then just continue, idky
        vector<vector<vector<int>>>dp(s1.size() + 1, vector<vector<int>>(s2.size() + 1, vector<int>(s3.size() + 1, 0)));
        //bc, if we have reached the end of all strings, then it was possible
        //if(i == s1.size() && j == s2.size() && k == s3.size()) return 1;
        //if(dp[i][j][k] != -1) return dp[i][j][k];
        dp[s1.size()][s2.size()][s3.size()] = 1;

        for(int I = s1.size(); I >= 0; I--){
            for(int J = s2.size(); J >= 0; J--){
                for(int K = s3.size(); K >= 0; K--){
                    if(I == s1.size() && J == s2.size() && K == s3.size()) continue;
                    bool flag = false; //this flag part was not intuitive
                    if(I < s1.size() && s1[I] == s3[K]){
                        flag = flag || dp[I + 1][J][K + 1];
                    }
                    if(J < s2.size() && s2[J] == s3[K]){
                        flag = flag || dp[I][J + 1][K + 1];
                    }

                    dp[I][J][K] =  flag;
                }
            }
        }
        return dp[0][0][0];
    }
    bool isInterleave(string s1, string s2, string s3) {
        int i = 0, j = 0, k = 0;
        return recursionTabu(s1, s2, s3, i, j, k);
    }
};