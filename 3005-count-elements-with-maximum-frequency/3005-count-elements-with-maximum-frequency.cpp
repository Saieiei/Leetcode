class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        //M3 maxheap
        //hashing
        unordered_map<int, int> mp;
        for(const int& num: nums){
            mp[num]++;
        }

        //maxHeap
        priority_queue<int> q;
        //populate the q with the freq
        //traverse through the mp
        for(const pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            q.push(freq);
        }

        //now keep poping until u dont get the freq anymore
        int maxFreq = q.top();
        int ans = 0;
        while(!q.empty() && q.top() == maxFreq){
            q.pop();
            ans = ans + maxFreq;
        }
        return ans;
    }
};