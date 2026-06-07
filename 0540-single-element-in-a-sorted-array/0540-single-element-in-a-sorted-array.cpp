class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //brute force
        //XOR O(n)
        int ans = 0;
        for(const int& num: nums){
            ans = ans ^ num;
        }
        return ans;
    }
};