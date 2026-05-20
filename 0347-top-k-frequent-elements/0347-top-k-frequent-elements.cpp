class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //M5 bucket sorting
        unordered_map<int, int> mp;
        //hashing
        for(int num: nums){
            mp[num]++;
        }
        //bucketing
        vector<vector<int>> buckets(n+1); //<freq, num>
        //traverse through the mp
        for(pair<const int, int> it: mp){
            int num = it.first;
            int freq = it.second;
            //push it in, in the correct buckets
            buckets[freq].push_back(num);
        }
        //return the top k freq elements
        vector<int> ans;
        //we will start from the bucket which has highest freq
        //freq = row
        for(int freq=n; freq>=0; freq--){
            for(const int& num: buckets[freq]){
                if(ans.size()<k){
                    ans.push_back(num);
                }
            }
        }
        return ans;
    }
};