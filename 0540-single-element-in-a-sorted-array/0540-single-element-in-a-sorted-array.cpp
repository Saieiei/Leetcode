class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //this will only come from exp
        //like u will not know when to move left or when to move right  and how to return
        int left = 0, right = nums.size()-1;
        int mid = left + (right - left)/2;
        //so here we will make it a point to return left (idk y)
        while(left < right)
        {
            mid = left + (right - left)/2;
            //we will mkae sure that mid is alwats even
            if(mid %2 ==1) mid--;
            
            if(nums[mid] == nums[mid+1]) left = mid +2;
            else right = mid;
        }
        return nums[left];
    }
};