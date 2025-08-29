#include<algorithm>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //this is simple only, but we start from back side
        //stack<pair>, pair-> <temp, days>
        //we also need ans which is a vector to keep the track of the final days that we get for each temp
        //initially just push in the temp with 0 days and update the ans vector
        //if u get a temp that is bigger than than top() then simply keep poping until u get a top()<temp and keep adding up the days
        //while popping if u the stack is empty then just push in the temp with 0 days and update the ans vector
        //but if the stack is not empty and u get a top()<temp, then simply push in the temp and 1+ the accumulated days and update the ans vector
        //in the end reverse the ans vector and return it

        vector<int> ans;
        stack<pair<int, int>> st; //<temp, days>

        //initially just push in the temp with 0 days
        if(st.empty()) st.push({temperatures[temperatures.size()-1], 0});
        ans.push_back(0);
        //we will start from the back
        for(int i=temperatures.size()-2; i>=0; i--)
        {
            int temp = temperatures[i];
            int accumulator = 0; //days
            ////if the stack is empty simply push with 0
            //if(st.empty()) st.push({temp, 0});
            //ans.push_back(accumulator);

            //temp >= st.top().first then simply pop and accumulate the days
            if(!st.empty() && temp >= st.top().first)
            {
                while(!st.empty() && temp >= st.top().first) //st is not empty
                {
                    accumulator = accumulator + st.top().second;
                    st.pop();
                }
                if(st.empty()) //after continous poping in case it goes empty
                {
                    st.push({temp, 0}); //temp remainded the bigesset during the popping
                    ans.push_back(0);
                    accumulator = 0;
                } 
            }
            if(temp < st.top().first) //then simply push with the updated days
            {
                int days = 1+accumulator;
                st.push({temp, days});
                ans.push_back(days);
                accumulator = 0;
            }

        }
        //reverse and return 
        reverse(ans.begin(), ans.end());
        return ans;
    }
};