class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //we will use stack and a new vector concept
        //the stack will be used to refer the index of the temperature vector
        //the new vector (ans) will be used to store the difference of the index
        //we will go from behind
        //in the stack we will push the last element(index) of the vector and push 0 in the ans vector
        //then we will see the 2nd last element of the vector and we will compare if the elment is greater than the 1 in the stack, 
            //if greater then we will find out the difference of the indexes and put it in the ans vector,
            //else then we pop the top element of the stack and then compare the element the top element of the stack with the tep
        //this process will be going on until we find a number in the stack that is greater than the temp
        //but if all the elements have been popped then we will have to push the element in the stack(index) and push 0 in the ans vector
        //in the end reverse the ans vector

        stack<int>s;
        vector<int> ans;
        int n=temperatures.size()-1; //last index
        for(int i=n;i>=0;i--)
        {
            if(s.empty())
            {
                s.push(i);
                ans.push_back(0);
            }
            else
            {
                while(!s.empty() && temperatures[i]>=temperatures[s.top()])
                {
                    s.pop();
                }
                if(s.empty())
                {
                    s.push(i);
                    ans.push_back(0);
                }
                else
                {
                    ans.push_back(s.top()-i);
                    s.push(i);
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
        //u can also use use 2 pointers approach but that will be O(n^2)
    }
};