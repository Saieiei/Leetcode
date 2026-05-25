class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        //Brute force, use hash map with N space

        //find the freq
        unordered_map<int, int>mp;
        for(const int& num: nums){
            mp[num]++;
        }

        //traverse through the mp
        //if u find any ele whos freq is > n/2
        //return that
        for(const pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            if(freq >n/2){
                return num;
            }
        }
        //if not possible
        return -1;
    }
};