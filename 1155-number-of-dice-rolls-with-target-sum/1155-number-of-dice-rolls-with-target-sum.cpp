//M4 SO-1
//we will take 1 dice and use all its faces(values)
    //as we keep going we will reduce the target and the no of dices used
class Solution {
public:
    long long int mod = 1000000007; //we use this mod because the q is telling us to use it

    int recursionSO1(int n, int k, int target){
        //1. we just need 2 rows(curr, prev)
        vector<int> curr(target+1, 0); vector<int> prev(target+1, 0);
        //dp[0][0] = 1; is basically the 1st block, and the 1st block in our logic comes in prev[0]
        prev[0] = 1;

        //2. for loop, reverse, copy-paste, fun-call, indexing
        for( int i = 1; i<=n; i++){
            //reset curr
            fill(curr.begin(), curr.end(), 0);
            for(int t = 1; t<=target; t++){
                int ans = 0;
                for(int value=1; value<=k; value++){
                    //we r doing this because t-value could go in negatives
                    if(t-value >= 0)
                        curr[t] = (curr[t] + prev[t-value]) %mod; //we use mod because the q is telling us
                }
                
            }
            //shifting
            prev = curr;

        }

        //3. return accordingly (return anything its fine, (prev = curr))
        return prev[target];
    }

    int numRollsToTarget(int n, int k, int target) {
        return recursionSO1(n, k, target);
    }
};