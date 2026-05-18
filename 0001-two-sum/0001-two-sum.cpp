//unordered map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mp;
        
        for(int i=0; i<n; i++){
            int compliment = target - nums[i];
            //check if that compliment (key) is present in the mp
            if(mp.count(compliment)){
                //if found then return the indexes
                return {i, mp[compliment]};
            }
            else{
                //if not found simply push the key and value in mp
                mp[nums[i]] = i;
            }
        }
        //if nothing return empty vector
        return {};
    }
};