class Solution {
public:
    string decodeString(string s) {
        int n = s.length();
        stack<char> st;
        string ans = "";

        for(int i=0; i<n; i++){
            string temp = "";
            if(s[i] != ']'){
                st.push(s[i]);
            }
            else{
                while(!st.empty() && st.top() != '['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                string numCh = "";
                while(!st.empty() && st.top() >= '0' && st.top() <= '9'){
                    numCh.push_back(st.top());
                    st.pop();
                }
                reverse(numCh.begin(), numCh.end());
                int num = stoi(numCh);
                string temp2 = "";
                for(int j=0; j<num; j++){
                    temp2 += temp;
                }
                reverse(temp2.begin(), temp2.end());


                for(int i=0; i<temp2.size(); i++){
                    st.push(temp2[i]);
                }
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};