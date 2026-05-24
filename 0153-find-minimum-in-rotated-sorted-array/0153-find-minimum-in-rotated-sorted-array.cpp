class Solution {
public:
    int findMin(vector<int>& nums) {
        //Brute Force O(N)
        int ans = *min_element(nums.begin(), nums.end());
        return ans;
    }
};