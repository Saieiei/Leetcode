class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //brute force
        //unorderedMap O(n) O(n)
        unordered_map<int, int>mp;
        //populate the mp
        for(const int& num: nums){
            mp[num]++;
        }
        //traverse through the mp 
        //and find out the single piece
        for(const pair<const int, int>it: mp){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
    }
};