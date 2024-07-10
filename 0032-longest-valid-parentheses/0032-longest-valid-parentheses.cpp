class Solution {
public:
//week 11
    int longestValidParentheses(string s) {
        //we can solve this q using stack
        //by default in the stack we will put -1, because if -1 is not removed from the stack, that means we never had a valid brackets and len will never be calculated, hence we will rerturn max, that will be 0 innitially
        //see if we get a (, then simply push it
        //if we get a ) and the stack is empty just push it, 
            //if the stack is not empty then we have to calc the diff in length, and update the max len

        int maxLen = 0;
        stack<int> st;

        st.push(-1);

        for(int i=0;i<s.length(); i++) //we will use forloop as we need the indexes
        {
            char ch = s[i];
            if(ch == '(') st.push(i);
            else //if we get a )
            {
                st.pop();
                if(st.empty()) st.push(i);
                else
                {
                    int len = i - st.top();
                    maxLen = max(len, maxLen);
                } 
            }
        }
        return maxLen;
    }
};