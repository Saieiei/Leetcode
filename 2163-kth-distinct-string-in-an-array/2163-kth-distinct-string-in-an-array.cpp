class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> ans;
        for(string s: arr)
        {
            if(count(arr.begin(), arr.end(), s)==1)
            {
                //cout<<"inside 1st if statement " << s<< endl;
                //if(count(ans.begin(), ans.end(), s) == 0)
               // {
                    ans.push_back(s);
                //}
            }
        }
        if(ans.size() < k) return "";
        else
        {
            return ans[k-1];
        }
    }
};