//prefix sum
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        vector<int> postfixSum(n, 0);

        //populate prefixSum
        for(int index=1; index<n; index++){
            //we start from 1 and not 0 because
            //0 index the prefixSum is 0
            prefixSum[index] = prefixSum[index-1] + nums[index-1];
        }
        //populate postfixSum
        for(int index=n-2; index>=0; index--){ 
            //we start from n-2 and not n-1 because
            //n-1 index the postfixSum is 0
            postfixSum[index] = postfixSum[index+1] + nums[index+1];
        }
        //find the index whos value is the same
        for(int index=0; index<n; index++){
            if(prefixSum[index] == postfixSum[index]){
                return index;
            }
        }
        return -1;
    }
};