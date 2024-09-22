class Solution {
public:
//week 8
//we will solve this using recursssion and DnC

    int maxSumArrayHelper(vector<int> &nums, int start, int end)
    {
        //base case
        if(start==end) return nums[start]; //single element
        //calculation
        int mid=start+((end-start)>>1);
        //recurssion
        int maxLeftSum=maxSumArrayHelper(nums, start, mid);
        int maxRightSum=maxSumArrayHelper(nums, mid+1, end);

        int maxLeftBorderSum=INT_MIN, maxRightBorderSum=INT_MIN;
        //max corss border
        int leftBorderSum=0, rightBorderSum=0;
        //from mid to left
        for(int i=mid;i>=start;i--)
        {
            leftBorderSum = leftBorderSum + nums[i];
            maxLeftBorderSum = max(maxLeftBorderSum, leftBorderSum);
        }
        //from mid to right
        for(int i=mid+1;i<=end;i++)
        {
            rightBorderSum = rightBorderSum + nums[i];
            maxRightBorderSum = max(maxRightBorderSum, rightBorderSum);
        }
        //from right to left through mid
        int crossBorderSum = maxRightBorderSum + maxLeftBorderSum;
        return max(crossBorderSum, max(maxLeftSum, maxRightSum));
    }

    int maxSubArray(vector<int>& nums) {
        //int ans=maxSumArrayHelper(nums, 0, nums.size()-1);
        //return ans;
        // Initialize currentSum and maxSum
    int currentSum = nums[0];
    int maxSum = nums[0];

    // Iterate through the array starting from the second element
    for(int i = 1; i < nums.size(); i++) {
        // Update currentSum by either adding the current element to the previous sum
        // or starting a new subarray from the current element
        currentSum = max(nums[i], currentSum + nums[i]);

        // Update maxSum if currentSum is greater
        maxSum = max(maxSum, currentSum);
    }

    // Output the result, which is the maximum sum of any subarray
    //cout << maxSum << endl;

    return maxSum;
    }
};