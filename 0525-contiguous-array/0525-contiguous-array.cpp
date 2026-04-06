//optimised
//prefix-sum, hashmaps
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                sum += -1;
            }
            else{
                sum += 1;
            }
            if(sum == 0){
                maxLength = i + 1;
            }
            else if(mp.find(sum) != mp.end()){ //found it
                int tempLength = i - mp[sum];
                maxLength = max(maxLength, tempLength);
            }
            else{ //not there in hash map, save the index
                mp[sum] = i;
            }
        }
        return maxLength;
    }
};