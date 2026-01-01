//M5 SO (Khadanaes Algo)
//we will start from the end
//Idea: should we consider this only elem or add up this eleme with the previous1
//in the end return the max so far found
//this Tabulation is a little diff because of 1 global variable
class Solution {
public:

    int recursionTabuSO(vector<int>& nums, int end){
        //bc
        int prev = nums[0];
        int globalMax = prev;
        int curr = 0;


        //2.forloop, reversed, fun-rec, indexing
        for(int i = 1; i <= end; i++){
            int PrevIndxMax = prev;
            curr = max(nums[i], nums[i] + PrevIndxMax);
            globalMax = max(curr, globalMax);

            //forgetting step
            prev = curr;
        }

        return globalMax;
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size()-1;
        return recursionTabuSO(nums, n);

    }
};