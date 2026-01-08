//M3 Tabulation
//idea is to inrease the diff more such that P1 can win
class Solution {
public:

    int recursionTabu(vector<int>& nums, int start, int end){
        //bc
        vector<vector<int>>dp(nums.size()+1, vector<int>(nums.size()+1, -1)); //not 0
        for(int i = 0; i <= nums.size()-1; i++){ //bc
            dp[i][i] = nums[i];
        }


        for(int start = nums.size()-2; start >= 0; start--){ //nums.size()-1 already care
            for(int end = start + 1; end <= nums.size()-1; end++){ // we will start from start because of the diagonal
                int startDiff = nums[start] - dp[start + 1][end];     //but since [start][start] already taken care we will start from +1
                int endDiff = nums[end] - dp[start][end - 1];
                dp[start][end] = max(startDiff, endDiff);
            }
        }
        return dp[0][nums.size()-1];
    }
    bool predictTheWinner(vector<int>& nums) {
        int diffMax =  recursionTabu(nums, 0, nums.size()-1);
        return diffMax >= 0;
        
    }
};