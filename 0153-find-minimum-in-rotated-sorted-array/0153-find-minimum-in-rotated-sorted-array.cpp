class Solution {
public:
    int findMin(vector<int>& nums) {
        //simple Binary search
        //after u get the mid element, check if the
        //high is < the mid, then uk that u have to pull low to mid+1
        //but if the mid element is > low element, then u have to pull
        //high to mid and not mid-1, cuz mid could be an answer
        //finally return low
        int n = nums.size();
        int low = 0;
        int high = n-1;
        //start the process
        //if both same then end it
        while(low < high){
            int mid = low + (high - low)/2;
            //check if the mid > high 
            //pull low to mid+1
            if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                //basically mid < low
                //then move high to mid
                high = mid;
            }
        }
        return nums[low];
    }
};