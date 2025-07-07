class Solution {
public:
    string longestPalindrome(const string& s) {
        if (s.empty()) return "";
        start = 0;
        max_len = 1;
        for (int i = 0; i < (int)s.size(); i++) {
            expand_around_centre(i, i, s);
            expand_around_centre(i, i + 1, s);
        }
        return s.substr(start, max_len);
    }

private:
    int start;
    int max_len;

    // now private—only callable from within Solution
    void expand_around_centre(int l, int r, const string& s) {
        while (l >= 0 && r < (int)s.size() && s[l] == s[r]) {
            int curr_len = r - l + 1;
            if (curr_len > max_len) {
                max_len = curr_len;
                start = l;
            }
            l--;
            r++;
        }
    }
};
