class Solution {
public:
    void recursion(vector<int>& candidates, int target, vector<int>& currAns, 
        vector<vector<int>>& ans, int index){
        //bc
        if(target == 0){
            ans.push_back(currAns);
            return;
        }
        if(target < 0){
            //simply return, as the candicate used was very high
            return;
        }
        //traverse through the loop
        for(int j = index; j<candidates.size(); j++){
            //use it
            currAns.push_back(candidates[j]);
            //recursion, we can pass teh same index, because that candate can be reused
            recursion(candidates, target - candidates[j], currAns, ans, j);
            //undo recursion
            currAns.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //if we r using the candiddate, we ahve to reduce the target
        //we will use currAns and push it in ans and return ans
        //if the target becomes - then we have ditch it
        //if the target becomes 0, then we have achieved it
        //we need index as well to traverse through the loop
        vector<int> currAns;
        vector<vector<int>> ans;
        int index = 0;
        recursion(candidates, target, currAns, ans, index);
        return ans;
    }
};