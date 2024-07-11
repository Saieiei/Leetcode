class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
       deque<int> dq;
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            // Remove elements from the back if they are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current element's index to the deque
            dq.push_back(i);

            // Remove the element from the front if it's outside the current window
            if (dq.front() == i - k) {
                dq.pop_front();
            }

            // Start adding results to the output list after the first k elements
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result; 
    }
};