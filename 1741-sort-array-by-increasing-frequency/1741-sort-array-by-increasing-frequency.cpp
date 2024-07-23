class Solution {
public:
    static bool compare (const  pair<int, int>& a, const  pair<int, int>& b )
    {
        //if freq same, then sort in decresing order
        if(a.second == b.second) return a.first > b.first;
        //else return in increasing order
        return a.second < b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        //we will sort this using custom comparator

        //1st we willl calculate the freq
        unordered_map<int, int>freqMap;
        for(int i: nums)
            freqMap[i]++;

        //next we will crate a vector<pair> and put all th emap values into this ans sort it
        vector<pair<int, int>> freqPair; //(element, frequency)
        for(auto entry: freqMap)
        {
            int ele = entry.first;
            int freq = entry.second;
            freqPair.push_back({ele, freq});
        }

        //now we will sort this vector
        sort(freqPair.begin(), freqPair.end(), compare);

        //after this pair has been sorted, we will create a vector to return
        vector<int> ans;
        for(auto entry: freqPair)
        {
            for(int i=0; i<entry.second; i++) ans.push_back(entry.first);
        }
        return ans;
    }
};