//we can do this in O(N) instead of O(N^2)
//we have to keep track of the sum in hashMap
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        //1st convert all the 0 -> -1
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }

        //now keep the track of the sums in hashmap
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            int tempAns = 0;
            sum = sum + nums[i];
            //0
            if(sum == 0){
                tempAns = i + 1;
            }
            //if some other value then 1st check in mp
            else if(sum != 0){
                auto it = mp.find(sum);
                if(it != mp.end()){
                    //found it
                    tempAns = i - mp[sum];
                }
                else{
                    //if not there in map, then its a new value
                    //push the index in the mp
                    mp[sum] = i;
                }
            }
            ans = max(ans, tempAns);
        }
        return ans;
    }
};