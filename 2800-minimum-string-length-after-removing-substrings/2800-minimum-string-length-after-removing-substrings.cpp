class Solution {
public:
    int minLength(string s) {
        ////bruteforce, using find, erase
        //string s1 = "AB";
        //string s2 = "CD";
    //
        //while(true)
        //{
        //    if(s.find(s1) != string::npos)
        //    {
        //        int index = s.find(s1);
        //        s = s.erase(index, 2);
        //    }
        //    else if(s.find(s2) != string::npos)
        //    {
        //        int index = s.find(s2);
        //        s = s.erase(index, 2);
        //    }
        //    else
        //    {
        //        //no more possible
        //        break;
        //    }
        //}
        //return s.length();

        //now lets try with stack
        stack<char> st;

        for(char ch: s)
        {
            if(!st.empty() && ((st.top() == 'A' && ch == 'B') || (st.top() =='C' && ch =='D')))st.pop();
            else st.push(ch);

        }
        return st.size();
    }
};