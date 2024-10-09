class Solution {
public:
//week 11
    int minAddToMakeValid(string s) {
        ////we will solve this problem using stack
        //stack<char> st;
//
        //for(char ch: s)
        //{
        //    if(ch == '(') st.push(ch); //simply push the ( into the stack
        //    else //if u get )
        //    {
        //        if(!st.empty() && st.top() == '(') st.pop();//if the stack is not empty and the top of the stack is a opening bracket, then we can cancel
        //        else st.push(ch);// then simply push,
        //    }
        //}
        //return st.size();


        //u can also do it without stack
        //this is another method of solving without the use of a stack
        int open = 0;
        int close = 0;

        for(char ch: s)
        {
            if(ch == '(') open++;
            else
            {
                if(open>0) open--;
                else close++;
            }
        }
        return (open + close);
    }
};