class Solution {
public:
    bool isValid(string s) {
        //we will solve this using stacks
        stack<char> st;
        int len = s.length();
        for(int i=0; i<len; i++)
        {
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else //clossing bracket, hence we have to pop
            {
                //before we pop we have to see if the stack is empty or not
                if(st.empty()) return false; //not possible to pop
                else //if the stack is not empty, we have to check if the opening and closing bracket r matching
                {
                    if(ch == ')' && st.top() == '(') st.pop();
                    else if(ch == '}' && st.top() == '{') st.pop();
                    else if(ch == ']' && st.top() == '[') st.pop();
                    //wrong ordering 
                    else return false;
                }
            }
        }
        if(st.empty()) return true;
        else return false;   
        
    }
};