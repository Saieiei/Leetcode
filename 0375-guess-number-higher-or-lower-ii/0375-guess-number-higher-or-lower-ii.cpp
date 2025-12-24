//M3 Tabulation
//it is somewhat related to include/exclude principal
//The Idea: if we get into the worst path of each i, we can get to know how much amount is required to burn (max)
//if the number we have selected is not the ans, then the posibility of that number lies between [start x-1] and [x+1, end]
//we will be going into each of these ranges using recursion
//add up the false number as we keep going
//each index tell u the max amount needed to get the ans
//from all these index we will pick the "min to get the minimum amount of money you need to guarantee a win regardless of what number I pick."
class Solution {
public:

    int recursionMemo(int start, int end){
        //1.create dp
        vector<vector<int>> dp(end+2, vector<int>(end+2, 0));

        //2. for loop, reversed, copy-paste, fun-rec, indexing
        for(int ss = end; ss>=1; ss--){
            for(int ee = ss; ee<=end; ee++){

                //bassecase
                if(ss == ee) continue;

                int ans = INT_MAX;
                //recursion
                for(int i=ss; i<=ee; i++)
                {
                    int LowerBound = dp[ss][i-1];
                    int UpperBound = dp[i+1][ee];

                    int cost = i + max(LowerBound, UpperBound);
                    ans = min(ans, cost);
                    //ans = min(ans, i + max(recursion(start, i-1), recursion(i+1, end)));
                }
                //2. store and update the dp
                dp[ss][ee] = ans;
            }  

        }
        //3. return accordingly
        return dp[start][end];
    }

    int getMoneyAmount(int n) {
        //1. create DP vector<vector<int>> dp
        return recursionMemo(1, n);
    }
};