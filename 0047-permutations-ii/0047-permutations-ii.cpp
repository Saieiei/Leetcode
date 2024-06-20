//class Solution {
//public:
//
//    void HelperFunction(vector<int>& nums, vector<vector<int>> &ans, int start)
//    {   
//        //base condition
//        if(start>=nums.size())
//        {
//            ans.push_back(nums); //since we directly manupulating nums vector
//            return;
//        }
//
//        //calculation
//        for(int i=start; i<nums.size();i++)
//        {
//            //1st we will swap with with i and start, then increase start
//            swap(nums[i], nums[start]);
//            //RECURSSION
//            HelperFunction(nums, ans, start+1);
//            //BACKTRACKING
//            swap(nums[i], nums[start]);
//        }
//    }
//
//    //we will solve this using recurssion and Backtracking
//    vector<vector<int>> permuteUnique(vector<int>& nums) {
//        vector<vector<int>> ans;
//        int start = 0;
//        //we will directly update ans and nums vector, so need for return, hence call by reference
//        HelperFunction(nums, ans, start);
//        //now we dont need duplicates, so we can make use of sets
//        set<vector<int>> st(ans.begin(), ans.end());
//        //now we will put all the ans from set to ans again (no duplicates)
//        ans.clear();
//        for(auto i: st) ans.push_back(i);
//        return ans;
//    }
//
//    //below 1, we r using a code where we will not make use osets as it takes time, we will try to make this code a little better
//};

class Solution {
public:

    void HelperFunction(vector<int>& nums, vector<vector<int>> &ans, int start)
    {   
        //base condition
        if(start>=nums.size())
        {
            ans.push_back(nums); //since we directly manupulating nums vector
            return;
        }

        //calculation
        unordered_map<int, bool> visited;
        for(int i=start; i<nums.size();i++)
        {
            if(visited.find(nums[i])!= visited.end()) continue;
            visited[nums[i]] = true;
            //1st we will swap with with i and start, then increase start
            swap(nums[i], nums[start]);
            //RECURSSION
            HelperFunction(nums, ans, start+1);
            //BACKTRACKING
            swap(nums[i], nums[start]);
        }
    }

    //we will solve this using recurssion and Backtracking
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int start = 0;
        //we will directly update ans and nums vector, so need for return, hence call by reference
        HelperFunction(nums, ans, start);
        return ans;
    }

};