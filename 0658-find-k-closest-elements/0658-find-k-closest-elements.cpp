class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

        //this is a custom compartor sorting operator, this will sort(rearrange) the elements based on the differences with x in ascending order
        //int a is the 1st element and int b is the second element 
        //so if a is smaller than b wrt to the difference then we will keep a element 1st then b element 2nd and so on
        auto cmp = (int& a, int& b) {
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