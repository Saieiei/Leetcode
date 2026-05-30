class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //maxHeap NlogN
        //autiomatically, the front() has the value
        //of the sliding window
        vector<int> ans;
        priority_queue<pair<int, int>>pq; //value, index
        //push the 1st k inside
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }

        //get the 1st max element
        int maxValue = pq.top().first;
        ans.push_back(maxValue);

        for(int i=k; i<n; i++){
            //push new element
            pq.push({nums[i], i});
            //LAZY DELETION
            //now we have to remove the k+1th element
            //if its taking the 1st position we will kill it
            while(!pq.empty() && pq.top().second <=i-k){
                //pop
                pq.pop();
            }
            //now simply get the maxValue
            maxValue = pq.top().first;
            ans.push_back(maxValue);
        }
        return ans;
    }
};