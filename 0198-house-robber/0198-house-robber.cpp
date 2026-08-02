class Solution {
public:
    int recursion(vector<int>& nums, int index, const int n){
        //move dp inside, do not intialize this to -1
        //vector<int> dp(n+5, 0);
        //bc, but anyways, we have it defined already
        //dp[n] = 0;
        int curr = 0, next1 = 0, next2 = 0;
        //create the loop
        for(int index = n-1; index>=0; index--){
            //we have 2 options, either include the house and follow the rest
            //else exclude the house and follow the rest
            //include
            int include = nums[index] + next2;
            //exclude
            int exclude = 0 + next1;
            //returning dp
            curr = max(include, exclude);

            //exchange, imp
            next2 = next1;
            next1 = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        //SO
        ////to get the value of a dp[index] we require, dp[index+1] and dp[index+2]
        //we, do not need the rest
        //so simply curr=dp[index], next1=dp[index+1], next2=dp[index+2], 
        //finally exchange as we pass through the for loop
        //include exclude principal

        int index = 0;
        return recursion(nums, index, n);
    }
};