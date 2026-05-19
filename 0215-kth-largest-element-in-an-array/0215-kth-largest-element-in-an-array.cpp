class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //M1 sorting
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};