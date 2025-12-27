//M1 Space Optimized of Maximum Height by Stacking Cuboids (LIS) 
//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/submissions/1866619969/
//so we dont do individial sorting but do the main sorting only

class Solution {
public:

    bool check(vector<int>& curr, vector<int>& prev){
        //curr = bigger box, envelope
        //prev = smaller box, envelope
        //check if we can stack, insert prev on curr
        if(prev[0] < curr[0] && prev[1] < curr[1]) return true; //width and height of one envelope are greater
        else return false;
    }   

    int recursionTabuSO(vector<vector<int>>& nums, int curr, int prev){
        //1. create dp and update it too
        int n = nums.size();
        //vector<vector<int>>dp(n+1, vector<int>(n+1, 0)); //initialisizng all to 0 cuz of the basecase (return 0 when curr>=nums.size())
        vector<int> currRow(n+1);
        vector<int> nextRow(n+1);

        //2. loop-update, reversed, copy-paste, fun-decl, index
        for(int curr = n-1; curr>=0; curr--){
            for(int prev = curr-1; prev>=-1; prev--){
                int include = 0;
                //we will only include if prev is -1 (just starting) or when the curr>prev
                if(prev == -1 || check(nums[curr], nums[prev])){ //this we will have to check separately if we can stack it or not
                    //we move 1 step ahead (curr and prev) and incease the include value by 1
                    include = 1 + nextRow[curr+1];  //in col we have to do +1 (envelope) because of prev
                }
                int exclude = 0 + nextRow[prev+1]; //in col we have to do +1 because of prev //we dont update prev, cuz nothign was added 
                currRow[prev+1] = max(include, exclude);
            }
            //shifting
            nextRow = currRow;
        }
        //3. return accordingly 
        return nextRow[-1+1]; //+1 because of the prev which is -1 and it will cause probs
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());

        int curr = 0, prev = -1;
        return recursionTabuSO(envelopes, curr, prev);
        
    }
};