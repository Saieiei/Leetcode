class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        ////M1 sorting
        //sort(nums.rbegin(), nums.rend());
        //return nums[k-1];

        ////M2 maxHeap
        //priority_queue<int> pq;
        ////push all in pq
        //for(int num: nums){
        //    pq.push(num);
        //}
        ////return kth largest1
        //for(int i=0; i<k-1; i++){
        //    pq.pop();
        //}
        //return pq.top();

        //M3 minHeap -> save space
        priority_queue<int, vector<int>, greater<int>> pq;
        //push the 1st k elements in the pq
        for(int i=0; i<k; i++){
            pq.push(nums[i]);
        }
        //process the rest of the nums with just size k of the pq
        for(int i=k; i<n; i++){
            if(pq.top() < nums[i]){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};