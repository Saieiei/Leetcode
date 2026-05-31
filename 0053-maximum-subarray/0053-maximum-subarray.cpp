class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        //kadane algo O(N)
        //main: if sum < 0 , reset it to 0
        //alsways maSum in the begining should be nums[0]
        int maxSum = nums[0];
        int currSum = 0;
        //traverse
        for(int i=0; i<n; i++){
            currSum += nums[i];
            maxSum = max(maxSum, currSum);
            //negavtive check
            if(currSum < 0){
                //reset it to 0
                currSum = 0;
            }
        }
        return maxSum;
        
    }
};