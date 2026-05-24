class Solution {
public:
    int search(vector<int>& nums, int target) {
        //there is only 1 way to do it logN method
        //binary search
        //so basically 1 part of the nums is sorted
        //and the another part is sorted as well
        //the basic idea is to move to that part of the sorted array
        //where the target lives in that region
        int n = nums.size();
        int low = 0;
        int high = n-1;
        //start the process
        while(low<=high){
            int mid = low + (high - low)/2;
            //check if we have got the target
            if(nums[mid] == target){
                return mid;
            }
            //check if the 1st part is completely sorted or not
            if(nums[low] <= nums[mid]){
                //if its sorted, 
                //check if the target falls in this range or not
                if(target >= nums[low] && target < nums[mid]){
                    //if so narow the range
                    high = mid - 1;
                }
                else{
                    //its sorted, but target doesnt fall in this range
                    //move low
                    low = mid + 1;
                }
            }
            else{
                //the 2st part is not sorted, so this part should be
                //check if the target falls in this range or not
                if(target > nums[mid] && target <= nums[high]){
                    //if so narow the range
                    low = mid + 1;
                }
                else{
                    //its sorted, but target doesnt fall in this range
                    //move high
                    high = mid - 1;
                }
            }
        }
        //not possible
        return -1;
    }
};