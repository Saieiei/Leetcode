class Solution {
public:
//its similar to this https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1
    int findKthLargest(vector<int>& nums, int k) {
        //since this is kth largest element, we will be doing it to minHeap
        priority_queue<int, vector<int>, greater<int> >pq;

        //1st push in 1st k elements in minHeap
        for(int i=0; i<k; i++)pq.push(nums[i]);

        //2nd since they need the largent element, then traverse throught the rest of the nums
        //if that num is greater than the top, then pop the pup and push this in the minHeap
        for(int i=k; i<=nums.size()-1; i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        return pq.top();
    }
};