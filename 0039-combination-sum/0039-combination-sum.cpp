class Solution {
public:
//week8
//we will be doing it using recurssion and backtracking

    void combinationHelper(vector<int>& candidates, int target, vector<int> &temp, vector<vector<int>> &ans, int index)
    {
        //base cases
        //we have reached 0
        if(target==0) 
        {
            ans.push_back(temp);
            return;
        }
        if(target<0) //it becomes negative which means that the number is big
        {
            //dont do anythign just return as we have the pop function in the main body itself
            return;
        }

        //calculations
        for(int i=index;i<candidates.size();i++)
        {
            temp.push_back(candidates[i]);
            combinationHelper(candidates, target-candidates[i], temp, ans, i);
            //backtracking
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        //temp ans ans vectors r going to be dynapic, hence no returns
        combinationHelper(candidates, target, temp, ans, 0);
        return ans;
    }
};