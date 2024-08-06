class Solution {
public:
//O(n2)
    //vector<int> replaceElements(vector<int>& arr) {
    //    vector<int> ans;
//
    //    for(int i=0;i<arr.size();i++)
    //    {
    //        if(arr.size()-1 == i) ans.push_back(-1);  //last element is alsoways -1
    //        else
    //        {
    //            auto ele = (max_element(arr.begin()+i+1, arr.end())); //O(n2)
    //            ans.push_back(*ele);
    //        }
    //    }
    //    //ans[arr.size()-1] = -1;
    //    return ans;
    //}
    vector<int> replaceElements(vector<int>& arr) {
        //O(n)
        vector<int> ans(arr.size(), 0);
        int maxi=-100000;
        //reverse order
        ans[ans.size()-1] = -1;
        for(int i=ans.size()-2; i>=0; i--)
        {
            maxi = max(maxi, arr[i+1]);
            ans[i] = maxi;
        }
        return ans;
    }
};