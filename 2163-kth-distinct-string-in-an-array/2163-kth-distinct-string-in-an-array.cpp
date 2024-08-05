class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        //using count
        //vector<string> ans;
        //for(string s: arr)
        //{
        //    if(count(arr.begin(), arr.end(), s)==1)
        //    {
        //        ans.push_back(s);
        //    }
        //}
        //if(ans.size() < k) return "";
        //else
        //{
        //    return ans[k-1];
        //}

        //using unordered_map
        unordered_map<string, int> mp;
        int count = 0;
        for(int i=0; i<arr.size(); i++)
        {
            mp[arr[i]]++;
        }

        for(auto& s : arr) {
            if(mp[s] == 1 && --k == 0)
                return s;
        }
 
        return "";
    }
};