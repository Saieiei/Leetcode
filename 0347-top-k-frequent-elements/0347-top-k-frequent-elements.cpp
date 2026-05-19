class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       //M4 hashMap + minHeap -> space optimization
       unordered_map<int, int> mp;
       //populate the freq
       for(int num: nums){
        mp[num]++;
       }
       //create minHeap
       using p = pair<int, int>;
       priority_queue<p, vector<p>, greater<p>> pq;
       //push all that to a pq
       for(const pair<const int, int>& it: mp){
        int freq = it.second;
        int num = it.first;
        pq.push({freq, num});
        //pop if greater than size k
        //we only need the last k elements
        if(pq.size() > k){
            pq.pop();
        }
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