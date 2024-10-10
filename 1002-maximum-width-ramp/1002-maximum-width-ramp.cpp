class Solution {
public:
    //https://chatgpt.com/share/67076ffa-6d58-800e-b23f-d22fb84a2f26
    int maxWidthRamp(vector<int>& nums) {
        //u may not the intuition  at the beginging
        //but the thing is what we have to see are the indexes and not the values at the index
        // all u have to see is the diff between the indexes is large and not the values
        //so what we can do it, sort the stack in decending order by their values and insert only index in teh stack
        //now we will traverse from the back of the nums array
        //see if the number is greater than the value preseent at the top of stack,
        //if so just calc the value teh differeence in their indexes and pop the top element of the index
        //this is because we know that to get a greater difference we will have to know the next value in the stack should be less (decending order)

        stack<int> st;
        for(int i=0; i<nums.size(); i++)
        {
            //decending order by value but insert index
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                if(nums[st.top()]> nums[i]) st.push(i);
            }
        }

        int max_diff = INT_MIN;
        int diff = 0;

        for(int j=nums.size()-1; j>=0; j--)
        {
            //now we just have to check if that values r greater
            //if so just find the diff and update the max diff
            while(!st.empty() && nums[j] - nums[st.top()] >= 0)
            {
                //find out the distance and keep updating the maxdiff
                int index = st.top();
                diff = j - index;
                max_diff = max(max_diff, diff);
                st.pop();
            }

        }
        return max_diff;
    }
};