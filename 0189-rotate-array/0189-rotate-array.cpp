//formula based
//reverse
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        //1st do comple reverse
        reverse(nums.begin(), nums.end());
        //2nd is to reverse the 1st k elements
        reverse(nums.begin(), nums.begin() + k);
        //3rd reverse the rest
        reverse(nums.begin()+k, nums.end());
        return;
    }
};