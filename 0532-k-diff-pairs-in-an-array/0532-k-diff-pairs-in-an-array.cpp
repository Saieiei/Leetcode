class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        //using maps N, N
        unordered_map<int, int>mp;
        //populate the mp
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int uniquePairs = 0;
        //traverse throiugh the map
        for(const pair<const int, int>& it: mp){
            int num = it.first;
            int freq = it.second;
            //according to the condition i!=j
            if(k == 0){
                //we need atleast 2 of them
                if(freq>=2){
                    uniquePairs++;
                }
            }
            else{
                if(mp.count(num+k)){
                    uniquePairs++;
                }
            }
        }
        return uniquePairs;
    }
};