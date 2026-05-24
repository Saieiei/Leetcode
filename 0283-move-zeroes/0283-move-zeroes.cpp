class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //Optimal Method N
        //2 pointers
        //move 1stIndex only when 2nd Index found
        //and swap then 1st
        int n = nums.size();
        int i=0;
        //traverse through th rest
        for(int j=0; j<n; j++){
            if(nums[j] != 0){
                //swap them and update the index
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return;
    }
};