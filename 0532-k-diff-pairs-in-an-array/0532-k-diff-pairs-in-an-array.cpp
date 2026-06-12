class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        //2 pointers NlogN, N
        //we will use set to remove duplicates
        set<pair<int ,int>>st;
        //sort it 1st
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        //dw it wont go out of loop, easily
        while(i<n && j<n){
            if(i==j){
                //we cant accept it bot r at the same pos
                //just move j ptr fowd
                j++;
                continue;
            }
            int diff = nums[j] - nums[i];
            if(k == diff){
                //found it, push it and move fwd
                st.insert({nums[i], nums[j]}); //make_pair(i, j)
                i++;
                j++;
            }
            else if(diff>k){
                //bring i closer
                i++;
            }
            else{
                j++;
            }
        }
        return st.size();
    }
};