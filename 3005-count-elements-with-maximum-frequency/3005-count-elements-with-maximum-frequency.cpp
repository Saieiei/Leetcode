class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        //M2 bucket sorting
        //1st hashing
        unordered_map<int, int>mp;
        //populate the freq
        for(int num: nums){
            mp[num]++;
        }

        //2nd bucketing
        vector<vector<int>> buckets(n+1);
        //traverse through the mp and populate the buckets
        for(pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            //populate
            buckets[freq].push_back(num);
        }
        //find out the bucket which has the maximum freq
        //should not be empty
        int ans = 0;
        for(int i=n; i>=0; i--){
            //basically the row should have cols inside it
            int freq = i;
            if(!buckets[freq].empty()){
                //found something
                //traverse through this non-empty row
                for(int num: buckets[freq]){
                    ans = ans + freq;
                }
                break; // CRITICAL: Stop after processing the max frequency
            }
        }
        return ans;

    }
};