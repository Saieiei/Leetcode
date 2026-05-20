class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        //sliding window - implimentation2
        //1st find the sum of 1st k elements
        int maxSum = INT_MIN;
        int sum = 0;
        for(int i=0; i<k; i++){
            sum = sum + nums[i];
        }
        maxSum = sum;
        //slide the window for the rest of the elements
        for(int i=k; i<n; i++){
            int firstEle = nums[i-k];
            int lastEle = nums[i];
            sum = sum + lastEle - firstEle;
            maxSum = max(maxSum, sum);
        }
        return maxSum/(double)k;
    }
};