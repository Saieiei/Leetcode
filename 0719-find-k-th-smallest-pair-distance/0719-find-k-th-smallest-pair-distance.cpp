class Solution {
public:
    // Function to count pairs with distance <= mid
int countPairs(vector<int>& nums, int mid) {
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        // Use binary search to find the first j such that nums[j] - nums[i] > mid
        int j = upper_bound(nums.begin(), nums.end(), nums[i] + mid) - nums.begin();
        count += j - i - 1;
    }
    return count;
}
    int smallestDistancePair(vector<int>& nums, int k) {
        //vector<int> ans;
        //int n = nums.size();
        //for(int i=0; i<n; i++)
        //{
        //    for(int j=i+1; j<n;j++)
        //    {
        //        int diff = abs(nums[i] - nums[j]);
        //        cout<<diff<<endl;
        //        ans.push_back(diff);
        //    }
        //}
        //sort(ans.begin(), ans.end());
        //return ans[k-1];
        ////Time Limit Exceeded 16 / 19 testcases passed

        sort(nums.begin(), nums.end()); // Step 1: Sort the array

    int left = 0;
    int right = nums[nums.size() - 1] - nums[0]; // Maximum possible distance

    while (left < right) { // Binary search on the distance
        int mid = left + (right - left) / 2;
        int count = countPairs(nums, mid);
        if (count < k) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left; // The k-th smallest distance
    }
};