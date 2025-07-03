class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        //this is like two sums 
        //its simple only
        //frequency, not needed, we just need the 1st part
        unordered_map<int, int>mp;
        for(int num: nums) mp[num]++; 

        //but if k = 0, then basically it will start counting itself even though its wrong
        //to avoid this will we check on its frequency, if > 1 then ans++
        if (k == 0) {
            for (auto& [num, frequency] : mp) {
                if (frequency > 1) {
                    ans++;
                }
            }
        }
        //just find its complement, dw, big ones always win
        else
        {
            for(auto&  [num, _]: mp)
            {
                if(mp.find(num-k) != mp.end()) ans++;
            }
        }
        return ans;
    }
};