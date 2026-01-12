//M1 Recursion
//Not intuitive rather typical
//we will keep doing operations until target becaomes 0 and we have used all the indexes
//2 options + or -
//in the end add all those options 
class Solution {
public:
    int recursion(vector<int>& nums, int target, int indx){
        //bc
        if(indx >= nums.size()){
            if(target == 0) return 1;
            else return 0;
        }

        int plus = recursion(nums, target - nums[indx], indx+1);
        int mins = recursion(nums, target + nums[indx], indx+1);
        return plus + mins;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int indx = 0;
        return recursion(nums, target, indx);
    }
};