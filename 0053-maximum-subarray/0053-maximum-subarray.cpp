//M1 recursion (DnC)
//This is the most easiest method
//find the left sum, find the right sum, find the crossum, then do recursion with the mid
//return the max 
class Solution {
public:

    int crossMaxCalcFun(vector<int>& nums, int start, int mid, int end){

        int leftCalMax = INT_MIN;
        int sum = 0;
        for(int i = mid; i >= start; i--){
            sum = sum + nums[i];
            leftCalMax = max(leftCalMax, sum);
        }

        int RightCalMax = INT_MIN;
        sum = 0;
        for(int i = mid+1; i <= end; i++){
            sum = sum + nums[i];
            RightCalMax = max(RightCalMax, sum);
        }

        int total = leftCalMax + RightCalMax;
        return total;
    }

    int recursion(vector<int>& nums, int start, int end){
        //bc
        if(start == end) return nums[start]; //just return the 1 and only ele

        int mid = start + (end-start)/2;

        int leftMax = recursion(nums, start, mid); // ...***|...
        int rightMax = recursion(nums, mid+1, end); // ...|***...
        int crossMaxCalc = crossMaxCalcFun(nums, start, mid, end); //...***...
 
        return max(leftMax, max(rightMax, crossMaxCalc));
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size()-1;
        return recursion(nums, 0, n);
    }
};