//basically we will push in the 1st k elements in the heap and get the top
//the next next what we have to do is play with index to remove them as we move forward
//the formula is top->index <= i-k then keep poping
//to keep the track of the index too with the eleemnt we will use pairs in the heap

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        //proceess teh 1st k elements
        for(int i=0; i<k; i++){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        //now we will process the rest of the elemets
        for(int i=k; i<nums.size(); i++){
            pq.push({nums[i], i});

            while(pq.top().second <= i-k) pq.pop();

            ans.push_back(pq.top().first);
        }

        return ans;
    }
};