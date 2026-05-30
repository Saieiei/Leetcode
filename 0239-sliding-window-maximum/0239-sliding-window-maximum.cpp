class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        //deque N
        //the front element should be the max element
        deque<int> dq; //index
        vector<int> ans;
        for(int i=0; i<n; i++){
            //before u push, remove the old kth+1 elemnt
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }

            //if we have a new element > last ememnt
            //we can del that last ele as it will not survive
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }

            //now simply push the new index in the dq
            dq.push_back(i);

            //we have got the 1st k element, then get the max
            if(i >=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};