//M1 recursion
//we will find each possible substring
//then we will use recursion to find out if its palindrome or not

class Solution {
public:
    int start = 0;
    int maxLen = 1;
    bool recursion(string& s, int i, int j){
        //bc
        if(i >= j) return true;

        bool flag = false;
        if(s[i] == s[j]) {
            flag = recursion(s, i + 1, j - 1);
        }

        if(flag){
            int currLen = j - i + 1;
            if(currLen > maxLen){
                maxLen = currLen;
                start = i;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        for(int i = 0; i <= s.length() - 1; i++){
            for(int j = i; j <= s.length() - 1; j++){
                recursion(s, i, j);     
            }
        }
        return s.substr(start, maxLen);
    }
};