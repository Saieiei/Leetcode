class Solution {
public:
    static bool myCmp(const pair<int, int>a, const pair<int, int>b){
        return a.first>b.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
       //M1 hashMap
       unordered_map<int, int> mp;
       //populate the freq
       for(int num: nums){
        mp[num]++;
       }
       //push all that to a vec
       vector<pair<int, int>> pairVec;
       for(pair<const int, int> it: mp){
        int freq = it.second;
        int num = it.first;
        pairVec.push_back({freq, num});
       }
       //sort this vec with custom sort
       sort(pairVec.begin(), pairVec.end(), myCmp);
       //return the top k freq elements
       vector<int> ans;
       for(int i=0; i<k; i++){
        int num = pairVec[i].second;
        ans.push_back(num);
       }
       return ans;
    }
};