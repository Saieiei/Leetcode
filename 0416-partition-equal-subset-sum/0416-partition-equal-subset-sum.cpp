//M3 Tabulation
//we will solve this using include/exclude method
//we will divide the sum in half(target) and include means sub from the target until we get 0
class Solution {
public:

    bool recursionTabu(vector<int>& nums, int index, int target){
        int n = nums.size();

        //1.create and update the dp with BC
        vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, 0)); //nums.size() = row, target = col, 0 cuz of the BC (if(t==0)return 1)
        for(int i=0; i<=n; i++){ //cuz of the BC (if(target==0)return 1)
            dp[i][0] = 1;
        }

        //2. forloop, reversed, rec-fun, indexing
        for(int i=n-1; i>=0; i--){ //n-1 because of the bc (if(index >=n) return 0)
            for(int t=1; t<=target; t++){ //t=1 because of the bc (if(t==0)return 1)

                int include = 0;
                if(t - nums[i] >=0) //because teh sub can cause negative indexing which can cause problems
                    include = dp[i+1][t - nums[i]];
                int exclude = dp[i+1][t];

                dp[i][t] = (include || exclude);
            }
        }

        //3.return accordingly
        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {
        int index = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0); //add up all the ele in sum
        if(sum & 1) return 0; //bitwise, if 1 then odd else 0
        else{
            int target = sum >> 1; //divide it by 2
            return recursionTabu(nums, index, target);
        }
    }
};