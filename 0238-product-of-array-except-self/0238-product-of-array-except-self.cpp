//PREFIX SUM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        //just like pivot sum
        vector<int> prefixMul(n);
        vector<int> postfixMul(n);
        vector<int> ans(n);
        //inital cases
        prefixMul[0] = 1;
        postfixMul[n-1] = 1;
        //start the for loop for prefix
        for(int i=1; i<n; i++){
            prefixMul[i] = prefixMul[i-1] * nums[i-1];
        }
        //start the for loop for postfix
        for(int i=n-2; i>=0; i--){
            postfixMul[i] = postfixMul[i+1] * nums[i+1];
        }
        //get ur final answer
        //formula
        for(int i=0; i<n; i++){
            ans[i] = prefixMul[i] * postfixMul[i];
        }

        return ans;
    }
};