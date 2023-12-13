class Solution {
public:
    int xorr(vector<int>&nums) {
	int ans = 0;
	// 1. xor all values of array
	for(int i=0; i<nums.size(); ++i) {
		ans = ans^nums[i];
	}
	//2. xor all range items [0, N]
	int n = nums.size();
	for(int i=0;i<=n;i++) {
		ans ^= i;
	}
	return ans;
}
    int missingNumber(vector<int>& nums) {
        // return sortingMethod(nums);
	    return xorr(nums);
    }
};