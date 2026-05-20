class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        //M1 hash maps
        //create hash map
        unordered_map<int, int> mp;
        //populate the freq
        for(int num: nums){
            mp[num]++;
        }

        //traverse through the mp and find the highest freq
        int maxFreq = INT_MIN;
        for(pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            maxFreq = max(maxFreq, freq);
        }

        //find out hpw many numbers have the max freq
        int count = 0;
        for(pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            if(freq == maxFreq){
                count++;
            }
        }

        //return ans
        return count*maxFreq;

    }
};