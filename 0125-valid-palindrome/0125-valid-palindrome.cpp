class Solution {
public:
    bool isPalindrome(const string &s) {
        //we dont have to make a new string, filter out shit and then use 2 pointers
        //we  can directly start offf with 2 pointers
        int start = 0;
        int end   = (int)s.size() - 1;
        
        while (start < end) {
            // skip left
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            // skip right
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            
            // if they don’t match (case‐insensitive for letters), we’re done
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            
            // otherwise advance both pointers
            start++;
            end--;
        }
        
        return true;
    }
};
