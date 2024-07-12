class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;

        // Helper function to process pairs
        auto processPairs = [&](string& str, char first, char second, int points) {
            stack<char> st;
            string temp;
            for (char ch : str) {
                if (ch == second) {
                    if (!st.empty() && st.top() == first) {
                        ans += points;
                        st.pop();
                    } else {
                        st.push(ch);
                    }
                } else {
                    st.push(ch);
                }
            }
            while (!st.empty()) {
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            str = temp;
        };

        // Prioritize processing based on the higher point value first
        if (x > y) {
            processPairs(s, 'a', 'b', x);
            processPairs(s, 'b', 'a', y);
        } else {
            processPairs(s, 'b', 'a', y);
            processPairs(s, 'a', 'b', x);
        }

        return ans;
    }
};