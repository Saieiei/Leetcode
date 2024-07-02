class Solution {
public:
//https://www.youtube.com/watch?v=jo7E5K_pJ18
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        //we can solve this based on frequency
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int i: nums1)
        {
            mp[i]++;
        }
        for(int i: nums2)
        {
            if(mp[i]>0)
            {
                mp[i]--;
                ans.push_back(i);
            }
        }
        return ans;
    }
};