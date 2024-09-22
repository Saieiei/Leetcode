class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        //this is like a formula
        long long ans = 0;
        long long currentSequence = 0;
        for(int num: nums)
        {
            if(num == 0)
            {
                currentSequence = currentSequence+1;
                ans = ans + currentSequence;
            }
            else currentSequence = 0;
        }
        return ans;
    }
};