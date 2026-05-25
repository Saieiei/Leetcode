class Solution {
public:
    void sortColors(vector<int>& nums) {
        //since only 3 elements we could rather count them
        //N
        int n = nums.size();
        int zeros = 0;
        int ones = 0;
        int twos = 0;
        //traverse through the vector
        for(int num: nums){
            if(num == 0){
                zeros++;
            }
            else if(num == 1){
                ones++;
            }
            else{
                twos;
            }
        }    
        //rearrange now
        for(int i=0; i<n; i++){
            if(zeros > 0){
                nums[i] = 0;
                zeros--;
            }
            else if(ones > 0){
                nums[i] = 1;
                ones--;
            }
            else{
                nums[i] = 2;
                twos--;
            }
        }
        return;    
    }
};