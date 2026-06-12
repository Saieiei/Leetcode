class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //custom sort class
        auto myCmp = [&](int a, int b){
            int diffa = abs(x-a);
            int diffb = abs(x-b);
            return (diffa < diffb) || (diffa == diffb && a<b);
        };
        //method 1 custom sorting NlogN
        //1st lets apply the custom sorting
        sort(arr.begin(), arr.end(), myCmp);
        //now take the 1st k elemnts from the sorted arr
        vector<int>ans(arr.begin(), arr.begin() + k);
        //sort the ans again because the orginal array was in sorted condition
        sort(ans.begin(), ans.end());
        return ans;
    }
};