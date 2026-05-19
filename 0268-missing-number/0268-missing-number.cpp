//XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int num: nums){
            ans = ans^num;
        }
        for(int i=0; i<=n; i++){
            ans = ans^i;
        }
        return ans;
    }
};