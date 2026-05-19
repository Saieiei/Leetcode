class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ////M1 sorting
        //sort(nums.rbegin(), nums.rend());
        //return nums[k-1];

        //M2 maxHeap
        priority_queue<int> pq;
        //push all in pq
        for(int num: nums){
            pq.push(num);
        }
        //return kth largest1
        for(int i=0; i<k-1; i++){
            pq.pop();
        }
        return pq.top();
    }
};