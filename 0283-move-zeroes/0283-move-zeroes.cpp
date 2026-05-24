class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //optimal way 
        //2 pointers
        //move 1stIndex only when 2nd Index found
        //and swap then 1st
        int n = nums.size();
        int i=0;
        //traverse through th rest
        for(int i=0; i<n; i++){
            for(int j=1; j<n; j++){
                if(nums[i] == 0 && nums[j] != 0 && j>i){
                    //swap them and update the index
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
        }
        return;
    }
};