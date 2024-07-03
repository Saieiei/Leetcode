class Solution {
public:
    int minDifference(vector<int>& nums) {
        int length = nums.size();
        sort(nums.begin(), nums.end());

        if(length <= 4) return 0;
        else
        {
            //there r 4 cases 
            //case 1: all small nums[length-1] - nums[3];
            //case 2: all big nums[length-4] - nums[0]; 
            //case 3: 1 small 2 big nums[length-3] - nums[1];
            //case 4: 2 small 1 big nums[length-2] - nums[2];
           
           return  min({nums[length-1] - nums[3], nums[length-4] - nums[0], nums[length-3] - nums[1], nums[length-2] - nums[2]});
            
        }
    }
};