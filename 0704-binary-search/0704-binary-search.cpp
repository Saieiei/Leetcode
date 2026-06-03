class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        //Binary Search Logn
        //already sorted
        int low = 0;
        int high = n-1;
        //start the process
        while(low <= high){
            int mid = low + (high - low)/2;
            int midEle = nums[mid];
            if(midEle == target){
                return mid;
            } 
            else{
                if(midEle > target){
                    high = mid -1;
                }
                else{
                    low = mid + 1;
                }
            }
        }
        //not possible
        return -1;
    }
};