class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       //M3 hashMap + maxHeap
       unordered_map<int, int> mp;
       //populate the freq
       for(int num: nums){
        mp[num]++;
       }
       //create maxHeap
       priority_queue<pair<int, int>> pq;
       //push all that to a pq
       for(const pair<const int, int>& it: mp){
        int freq = it.second;
        int num = it.first;
        pq.push({freq, num});
       }
       //return the top k freq elements
       vector<int> ans;
       for(int i=0; i<k; i++){
        pair<int, int> frontData = pq.top();
        int freq = frontData.first;
        int num = frontData.second;
        ans.push_back(num);
        pq.pop();
       }
       return ans;
    }
};