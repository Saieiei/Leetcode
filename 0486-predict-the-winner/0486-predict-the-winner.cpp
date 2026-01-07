//M1 Recursion
//idea is to inrease the diff more such that P1 can win
class Solution {
public:

    int recursion(vector<int>& nums, int start, int end){
        //bc
        if(start == end)return nums[start];

        int startDiff = nums[start] - recursion(nums, start + 1, end);
        int endDiff = nums[end] - recursion(nums, start, end - 1);
        return max(startDiff, endDiff);
    }
    bool predictTheWinner(vector<int>& nums) {
        int diffMax =  recursion(nums, 0, nums.size()-1);
        return diffMax >= 0;
        
    }
};