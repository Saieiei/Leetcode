class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        //sorting NlogN
        sort(nums.begin(), nums.end());
        //bc
        if(nums.size() == 0){
            return 0;
        }
        //traverse through each element
        //check if teh next ele is correct
        //if so increase count
        int currElement = 0;
        int currSequence = 1;
        int maxSequence = 1;
        for(int i=1; i<n; i++){
            currElement = nums[i];
            //eliminate dups
            if(currElement != nums[i-1]){
                //this is safe
                //check if its in sequence
                if(currElement == nums[i - 1] + 1){
                    //sequence is correct
                    currSequence++;
                }
                else{
                    //some other element, have to reset the sequence
                    maxSequence = max(maxSequence, currSequence);
                    currSequence = 1;
                }
            }
        }
        // Final check in case the longest streak ends at the very last number
        return max(maxSequence, currSequence);
    }
};