//https://www.youtube.com/watch?v=ZW7yqTyxtP4
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // the range mentioned is [1-n] 
        //therefore we dont have to worry about the negative values
        for(int i=0;i<nums.size();i++)
        {
        while(nums[i]>0 && nums[i]<=nums.size() && nums[nums[i]-1]!=nums[i])
        {
            swap(nums[i], nums[nums[i]-1]);
        }
        }

        //now we will find the black sheep that should be a a vlue that doesnt match its corersponding index, for example at index 3 4 should be there
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1)
            return i+1;
        }
        return nums.size() +1; //if we have an array thats perfectly sorted with no missing values, then the smallest + element wil be 1+array size, for exmaple [1-5], 1[0],2[1],3[2],4[3],5[4] hence 6 will be ans
    }
};