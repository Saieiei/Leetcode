class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //optimised, O(1) space, Boyer-Moore voting.

        //candidate
        int count = 0;
        int candidate = nums[0];
        for(const int& num: nums){
            //CRITICAL
            if (count == 0) {
                candidate = num;
            }
            //part of the army
            if(num == candidate){
                count++;
            }
            //not part of the army
            else{
                count--;
            }
        }
        return candidate;
    }
};