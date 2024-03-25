class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
            vector<int> duplicates;

    // Iterate through the array
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1; // Get the index (using 0-based indexing)
        if (nums[index] < 0) { // If the number at this index is negative, it means we've seen it before
            duplicates.push_back(abs(nums[i])); // Add the duplicate to the result
        } else {
            nums[index] *= -1; // Mark this number as seen by making it negative
        }
    }

    return duplicates;
        
    }
};