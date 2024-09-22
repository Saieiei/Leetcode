class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int minLength = INT_MAX; // Initialize the minimum length to a large value
    int sum = 0; // To store the sum of the current subarray
    int left = 0; // Left pointer for the sliding window

    // Iterate over the array with the right pointer
    for (int right = 0; right < n; right++) {
        sum += nums[right]; // Add the current element to the sum
        
        // Shrink the window from the left as long as the sum is >= target
        while (sum >= target) {
            // Update the minimum length of subarray if found smaller
            minLength = min(minLength, right - left + 1);
            sum -= nums[left]; // Remove the element at the left from the sum
            left++; // Move the left pointer to the right
        }
    }

    // If no subarray with sum >= target is found, return 0
    return (minLength == INT_MAX) ? 0 : minLength;
    }
};