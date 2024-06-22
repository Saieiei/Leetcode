class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        int currentPrefixSum = 0;
        int niceSubarrayCount = 0;
        
        // Initialize the prefixCount map with 0 count having one occurrence
        prefixCount[0] = 1;
        
        for (int num : nums) {
            // Increment currentPrefixSum if num is odd
            currentPrefixSum += (num % 2);
            
            // Check if there exists a prefix sum that when subtracted by k results in currentPrefixSum
            if (prefixCount.find(currentPrefixSum - k) != prefixCount.end()) {
                niceSubarrayCount += prefixCount[currentPrefixSum - k];
            }
            
            // Increment the count of currentPrefixSum in the map
            prefixCount[currentPrefixSum]++;
        }
        
        return niceSubarrayCount;
    }
};