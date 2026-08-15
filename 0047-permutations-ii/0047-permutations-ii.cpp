class Solution {
public:
    void recursion(vector<int>nums, vector<int> currectAns, 
                    vector<vector<int>>& ans, vector<bool>& isVisited){
        //bc
        if(currectAns.size() == nums.size()){
            ans.push_back(currectAns);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            //1st check if that ele was used
            if(isVisited[i]){
                continue;
            }
            //is not used but we have to skip duplicates as well
            if(i>0 && nums[i] == nums[i-1] && isVisited[i-1] == false){
                continue;
            }

            //use it and mark it as visisted
            currectAns.push_back(nums[i]);
            isVisited[i] = true;
            //recursion
            recursion(nums, currectAns, ans,  isVisited);
            //undo and mark it as not visited
            currectAns.pop_back();
            isVisited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //simplest way is to use sets to avoid duplication
        //but its a bad approach and the uncessary branches r also calculated
        //so, we will not be swapping here, we will create a new vector
        //we will also have to check if we have used the ele or not, 
        //isVisisted[], so we will use a loop here
        //make sure to sort it because teh duplicates will be adjacent
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        vector<int> currectAns;
        vector<bool> isVisited(nums.size(), false);
        recursion(nums, currectAns, ans, isVisited);
        return ans;
    }
};