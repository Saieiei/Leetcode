//M3 Tabulation
//The target range can go in negative as well for the forloop, 
    //so take the max range of total of nums both the sides
//since target can go negative, we cannot use vector, rather map
//Not intuitive rather typical
//we will keep doing operations until target becaomes 0 and we have used all the indexes
//2 options + or -
//in the end add all those options 
class Solution {
public:
    int recursionTabu(vector<int>& nums, int target, int indx){
        map<pair<int, int>, int>dp; //index, Total -> ans
        dp[{nums.size(), 0}] = 1;
        ////bc
        //if(indx >= nums.size()){
        //    if(target == 0) return 1;
        //    else return 0;
        //}
        //if(dp.find({target, indx}) != dp.end()) return dp[{target, indx}];
        int total = 0;
        for(auto num:nums) total += num;

        for(int i = nums.size() - 1; i >= 0; i--){
            for(int T = -total; T <= total; T++){ 
                //the below 1 is a little diff tyype of recursion calling and inserting
                int plus = (dp.find({i+1, T - nums[i]}) != dp.end()) ? dp[{i+1, T - nums[i]}] : 0;
                int mins = (dp.find({i+1, T + nums[i]}) != dp.end()) ? dp[{i+1, T + nums[i]}] : 0;
                dp[{i, T}] = plus + mins;
            }
        }

        return dp[{0, target}];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int indx = 0;
        return recursionTabu(nums, target, indx);
    }
};