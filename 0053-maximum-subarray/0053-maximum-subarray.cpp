//M1 recursion (DnC)
//This is the most easiest method
//find the left sum, find the right sum, find the crossum, then do recursion with the mid
//return the max 
class Solution {
public:

    int crossMaxFun(vector<int>& nums, int start, int mid, int end){
        //we need to get the best leftSum and best rightSum from mid
        //                         <----|---->
        int currSum = 0;
        int bestLeftSum = INT_MIN;
        for(int i = mid; i >= start; i--){
            currSum += nums[i];
            bestLeftSum = max(bestLeftSum, currSum);
        }
        currSum = 0;
        int bestRightSum = INT_MIN;
        for(int i = mid+1; i <= end; i++){
            currSum += nums[i];
            bestRightSum = max(bestRightSum, currSum);
        }
        int crossSum = bestLeftSum + bestRightSum;
        return crossSum;
    }

    int recursion(vector<int>& nums, int start, int end){
        //the ans will bre the only element left out (max value)
        //bc, 
        if(start == end){
            return nums[start];
        }
        //we need mid to divide
        int mid = start + (end-start)/2;
        //I trust the recursion to get the left max
        int leftMax = recursion(nums, start, mid);
        //I trust the recursion to get the right max
        int rightMax = recursion(nums, mid+1, end);
        //we have to get the crossMax as well
        int crossMax = crossMaxFun(nums, start, mid, end);
        //get the max ans return it
        return max({leftMax, rightMax, crossMax});
    }

    int maxSubArray(vector<int>& nums) {
        //recursion
        int n = nums.size()-1;
        return recursion(nums, 0, n);
    }
};