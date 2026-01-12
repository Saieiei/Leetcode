//M2 Memoization
//since target can go negative, we cannot use vector, rather map
//Not intuitive rather typical
//we will keep doing operations until target becaomes 0 and we have used all the indexes
//2 options + or -
//in the end add all those options 
class Solution {
public:
    int recursionMemo(vector<int>& nums, int target, int indx, map<pair<int, int>, int>& dp){
        //bc
        if(indx >= nums.size()){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp.find({target, indx}) != dp.end()) return dp[{target, indx}];

        int plus = recursionMemo(nums, target - nums[indx], indx+1, dp);
        int mins = recursionMemo(nums, target + nums[indx], indx+1, dp);
        dp[{target, indx}] = plus + mins;
        return dp[{target, indx}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int indx = 0;
        map<pair<int, int>, int>dp;
        return recursionMemo(nums, target, indx, dp);
    }
};