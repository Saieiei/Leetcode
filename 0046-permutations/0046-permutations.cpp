class Solution {
public:
    void recursion(vector<int> nums, int index, vector<vector<int>>& ans){
        //bc
        if(index >= nums.size()){
            ans.push_back(nums);
            return;
        }
        //traverse through the nums
        for(int j = index; j<nums.size(); j++){
            //use it
            swap(nums[index], nums[j]);
            //recursion
            recursion(nums, index+1, ans);
            //undo
            swap(nums[index], nums[j]);
        }
        //return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        //use it, recurse, undo 
        //we will be swapping stuff in nums and push it in ans
        //we do noit care about duplicates, so no sets or isVisited[]
        //for swaping pusposes we will be using index, so we will use a for loop
        vector<vector<int>> ans;
        int index = 0;
        recursion(nums, index, ans);
        return ans;
    }
};