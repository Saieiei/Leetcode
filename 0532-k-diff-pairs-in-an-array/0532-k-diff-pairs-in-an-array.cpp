class Solution {
public:
    int BS(vector<int>& nums, int low, int high, int target){
        //start the process
        while(low<=high){
            int mid = low + (high - low)/2;
            if(target == nums[mid]){
                return 1;
            }
            else if(target > nums[mid]){
                low = mid + 1;
            }
            else{
                high  = mid - 1;
            }
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        //Binary Search NlogN, 1
        //no extra space 
        int uniquePairs = 0;
        //sort it 1st
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int low = i+1;
            int high = n-1;
            int target = nums[i] + k;
            if(BS(nums, low, high, target)!= -1){
                //we found 1
                uniquePairs++;
            }
        }
        return uniquePairs;
    }
};