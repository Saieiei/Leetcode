class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        //Optimised approach
        //Binary search o(logN)
        //the clue is that every element repaeats twice and its sorted
        //edge cases
        //no element
        if(n == 0){
            return -1;
        }
        //only 1 element
        if(n==1){
            return nums[0];
        }
        //2 diff ele=emnts
        if(n==2 && nums[0]!=nums[1]){
            return nums[0];
        }
        //check if the starting 1 is unique
        if(n>2 && nums[0] != nums[1]){
            return nums[0];
        }
        //check if the ending 1 is unique
        if(n>2 && nums[n-1] != nums[n-2]){
            return nums[n-1];
        }
        //for the remaining range
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high - low)/2;
            //check if u have got the unique element
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]){
                //unique
                return nums[mid];
            }
            else{
                //we have to decide to go left or right
                //this is based on the index even/odd 
                if(mid%2 == 0 && nums[mid] == nums[mid+1]||
                mid%2 == 1 && nums[mid] == nums[mid-1]){
                    //move right
                    low = mid + 1;
                }
                else{
                    //move left
                    high = mid -1;
                }
            }
        }
        return -1;
    }
};