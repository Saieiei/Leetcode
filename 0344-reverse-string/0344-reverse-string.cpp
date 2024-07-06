class Solution {
public:
    void reverseString(vector<char>& s) {
        //using STL
       //reverse(s.begin(), s.end());
       //return;

       //using 2 pointers approach
       //int p1 = 0;
       //int p2 = s.size() -1;
       //while(p1<p2)
       //{
       //     char temp = s[p1];
       //     s[p1] = s[p2];
       //     s[p2] = temp;
       //     p1++;
       //     p2--;
       //}
       //return;

        //using stacks
        stack<char> st;
 
        for(int i=0; i<s.size(); i++)
        {
             char ch = s[i];
             st.push(ch);
        }

        int i=0; 
        while(!st.empty())
        {
            char ch = st.top();
            s[i] = ch;
            i++;
            st.pop();
        }
        return;
    }
};