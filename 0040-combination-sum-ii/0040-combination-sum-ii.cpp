class Solution {
public:
    void recursion(vector<int>& candidates, int target, vector<int>& currAns, 
            vector<vector<int>>& ans, int index){
        //bc
        if(target == 0){
            ans.push_back(currAns);
            return;
        }
        for(int j = index; j<candidates.size(); j++){
            // Skip duplicate choices at the same level.
            if(j > index && candidates[j] == candidates[j - 1]) {
                continue;
            }
            // Since array is sorted,
            // no later candidate can work either.
            if(candidates[j] > target) {
                break;
            }
            //we will continue if the adj r duplicate or the target has gone neagtives
            //use it
            currAns.push_back(candidates[j]);
            //recursion, we should do j+1, cuz we cannot us eteh same cnadidate again
            recursion(candidates, target - candidates[j], currAns, ans, j+1);
            //undo
            currAns.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //same as combination 1
        //the most easiest way is to push the final findings in a set
        //but it is not cor rect cuz we will watse time in duplicate brnaches
        //better to avoid them by checking duplicates
        //1st we have to sort to keep the duplicates adjacent
        sort(candidates.begin(), candidates.end());
        vector<int> currAns;
        vector<vector<int>> ans;
        int index = 0;
        recursion(candidates, target, currAns, ans, index);
        return ans;
    }
};