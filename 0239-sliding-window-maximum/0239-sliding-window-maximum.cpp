class Solution {
public:
//week 12 
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  //this deque method requires O()
   deque<int> dq;
   //in the deque, we will store the indeex of the greatest element
    vector<int> result;
    //in case of sliding window, just rememebr this technique
        //while (condition)->pop_back()
        //push_back()
        //sliding window limit exceeded pop_front()
        //put the 1st elemet into the ans, after size of the sliding window, front()

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

    //we can do the same using sets, which can do it O(nlogn)
    //    vector<int> ans;
    //    set<pair<int, int>, greater<pair<int,int>>> st;
//
    //    // Initialize the set with the first k elements
    //    for (int i = 0; i < k; i++)
    //        st.insert({ nums[i], i });
//
    //    // The maximum element in the first window
    //    ans.push_back((st.begin())->first);
//
    //    // Process the remaining elements
    //    for (int i = k; i < nums.size(); i++) {
//
    //        // Remove the (i-k)th element from the window
    //        st.erase({ nums[i - k], i - k});
//
    //        // Add the current element to the set
    //        st.insert({ nums[i], i});
//
    //        // The maximum element in the current window
    //        ans.push_back(st.begin()->first);
    //    }
//
    //    return ans;

    }
};