class Solution {
public:
    string removeDuplicates(string s) {
        //this is super easy only becuse is just 2 elements
        //it can be done using stacks
        stack<char> st;

        //traverse through the string
        for(char ch : s)
        {
            //if empty? simply push
            if(st.empty()) st.push(ch);
            else //before poping always check if the stack is empty or not
            {
                if(!st.empty() && st.top() == ch) //same, paired, hence pop 
                    st.pop();
                else st.push(ch);
            }
        }

        string ans = ""; //its in the stack, but be careful of the order
        while(!st.empty())
        {
            ans = st.top() + ans; st.pop(); 
        }
        return ans;
    }
};