class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                // Pop characters until '(' is encountered
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }
                // Pop the '('
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                // Push the reversed string back into the stack
                for (char chTemp : temp) {
                    st.push(chTemp);
                }
            } else {
                st.push(c);
            }
        }
        
        // Construct the result from the stack
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};