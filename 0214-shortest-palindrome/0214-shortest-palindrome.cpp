class Solution {
public:
// Function to compute the LPS (longest prefix suffix) array
vector<int> computeLPSArray(string str) {
    int n = str.length();
    vector<int> lps(n, 0);  // LPS array of size n
    int len = 0;  // Length of the previous longest prefix suffix
    int i = 1;

    // Loop to fill lps[] for str
    while (i < n) {
        if (str[i] == str[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];  // Try shorter previous prefix
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

string shortestPalindrome(string s) {
    string rev_s = s;  // Reverse of the input string
    reverse(rev_s.begin(), rev_s.end());

    // Combine original string and reversed string with a special separator
    string combined = s + "#" + rev_s;

    // Get the LPS array for the combined string
    vector<int> lps = computeLPSArray(combined);

    // lps.back() tells us the longest palindromic prefix of 's'
    int longestPalindromicPrefixLength = lps.back();

    // Add the non-palindromic suffix in reverse to the start
    string suffixToAdd = rev_s.substr(0, rev_s.length() - longestPalindromicPrefixLength);

    // Final result is the reversed suffix + the original string
    return suffixToAdd + s;
}
};