class Solution {
public:
    // An iterative binary search function.
    int binarySearch(vector<int>& nums, int low, int high, int x)
    {
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if x is present at mid
            if (nums[mid] == x)
                return mid;

            // If x greater, ignore left half
            if (nums[mid] < x)
                low = mid + 1;

            // If x is smaller, ignore right half
            else
                high = mid - 1;
        }

        // If we reach here, then element was not present
        return low;
    }

    int searchInsert(vector<int>& nums, int target) {
        int x = target;
        int n = nums.size();
        int result = binarySearch(nums, 0, n - 1, x);
        return result;
    }
};