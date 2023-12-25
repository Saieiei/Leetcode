class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto cmp = [&](int a, int b) {
            int diffA = abs(a - x);
            int diffB = abs(b - x);
            return diffA < diffB || (diffA == diffB && a < b);
        };
        
        // Sorting the array based on the custom comparator
        sort(arr.begin(), arr.end(), cmp);
        
        // Extracting the first k elements
        vector<int> result(arr.begin(), arr.begin() + k);
        
        // Sorting the result to maintain ascending order
        sort(result.begin(), result.end());
        
        return result;
    }
};