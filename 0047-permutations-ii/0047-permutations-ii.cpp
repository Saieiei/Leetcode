class Solution {
public:
    void recursion(vector<int>nums, int index, vector<vector<int>>& ans){
        //bc
        if(index >= nums.size()){
            ans.push_back(nums);
        }
        //traverse through the nums
        for(int j=index; j<nums.size(); j++){
            //use it
            swap(nums[index], nums[j]);
            //recursion
            recursion(nums, index+1, ans);
            //undo
            swap(nums[index], nums[j]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //simplest way is to use sets to avoid duplication
        //but its a bad approach and the uncessary branches r also calculated
        //the same approach as to solve permutations but with sets
        //we will be swaping in nums itself, so we need index which we will use in a for loop
        //we will store all the permutations in an ans
        //which we will later convert it to a set to delete the dups
        vector<vector<int>> ans;
        int index = 0;
        recursion(nums, index, ans);
        set<vector<int>>st (ans.begin(), ans.end());
        ans.clear();
        for(vector<int> it: st){
            ans.push_back(it);
        }
        return ans;
    }
};