class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //prefixSum + hashmap
        unordered_map<int, int>prefixSum;
        //basecase
        //this is possible because 
        //we say prefix[0] i spossible atleast once
        prefixSum[0] = 1;
        
        int totalSubArrays = 0;
        int currentSum = 0;
        //start the process
        for(const int& num: nums){
            currentSum = currentSum + num;
            //formula
            int target = currentSum - k;
            //check if we have this traget in the prefixSum map
            if(prefixSum.count(target)){
                //found it
                totalSubArrays = totalSubArrays + prefixSum[target];
            }
            //anyways push the currentSum in the prefixSum map
            prefixSum[currentSum]++;
        }
        return totalSubArrays;
    }
};