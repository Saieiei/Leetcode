class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Optimised N in 1pass
        //3 pointers (dutch flag)
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int mid = 0;
        //we just have to swap low and mid or mid and high
        //u swap mid with low when its value is 0
        //if u swap low and mid increase both
        //u swap mid with high when its value is 2
        //if u swap mid and high, just decrease high
        //if u get mid value as 1, then simply move forward
        //we will stop when mid crosses high
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            }
            else{
                mid++;
            }
        }
        return;
    }
};