class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        //sliding window - implimentation1
        int i = 0; 
        int j = k-1;
        //1st find the sum of 1st k elements
        int maxSum = INT_MIN;
        int sum = 0;
        for(int k = i; k<=j; k++){
            sum = sum + nums[k];
        }
        maxSum = sum;
        //now move j by 1 step front
        j++;
        //now keep processing until we reach the end
        //from the sum sub i and add j pointer values
        while(j<n){
            sum = sum + nums[j] - nums[i];
            j++;
            i++;
            maxSum = max(maxSum, sum);
        }
        return maxSum/(double)k;
    }
};