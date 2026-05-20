//2 pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        //initially i = 0 and j = 1
        //we will only move i when j has found a unique elemnt
        //get that value from j and put it in i
        //keep processing until j has hit the end
        int i = 0;
        for(int j=1; j<n; j++){
           if(nums[i] != nums[j]){
            //unique element found
            i++;
            nums[i] = nums[j];
           } 
        }
        return i + 1;
    }
};