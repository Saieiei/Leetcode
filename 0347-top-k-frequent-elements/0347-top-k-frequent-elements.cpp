//bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        //hashing
        unordered_map<int, int>mp;
        for(int num: nums){
            mp[num]++;
        }

        //bucketing
        vector<vector<int>> buckets(n+1);
        vector<int> ans;
        //traverse through the map
        for(const pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            buckets[freq].push_back(num);
        }

        //populate the ans
        for(int i=n; i>=0; i--){
            if(ans.size() == k){
                break;
            }
            //check if that row is empty
            if(!buckets[i].empty()){
                //push the num in the ans
                for(int num: buckets[i]){
                    ans.push_back(num);
                    //check if we have reached the size
                    if(ans.size() == k){
                        return ans;
                    }
                }
            }
        }
        return {};
    }
};