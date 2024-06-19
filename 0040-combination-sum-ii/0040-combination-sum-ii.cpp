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
            if(i>index && candidates[i]==candidates[i-1]) continue; //this is imp or else TLE 172/176
            temp.push_back(candidates[i]);
            combinationHelper(candidates, target-candidates[i], temp, ans, i+1); 
            //backtracking
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //we will sort it because look at the sample vectors, they r in sorted order only
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        //temp ans ans vectors r going to be dynapic, hence no returns
        combinationHelper(candidates, target, temp, ans, 0);
        //we will put in ans into set and remove any duplicate vectors
        set<vector<int>> st;
        for(auto x: ans)
        {
            st.insert(x); //dont use push_back, it wont work, with set u should  use 'insert' or, st(ans.begin(), ans.end());
        }
        //now again we the correct ans in st and not in ans vector, so lets remove all the elements from ans vectors and put in the correct values into ans vectors
        ans.clear();
        for(auto x: st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};