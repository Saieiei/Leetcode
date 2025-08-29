#include<algorithm>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //this 1 is more of a formula based to find the next big element

        vector<int> ans(temperatures.size(), 0); //we need to do this because we will not cal the last 1 and it will be 0 by default
        stack<int> st;

        for(int i=0; i<temperatures.size(); i++)
        {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                ans[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

//auto init = atexit([](){ofstream("display_runtime.txt") << 0;});