class Solution {
public:
    int expandFromCentre(string s, int left, int right){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        //expland from centre
        //N
        //traverse through the chars in s
        //try to expand from the centre
        //we have to find len for both even and odd
        //after we get the maxLen and the startting point
        //we can get the substr
        int start = 0;
        int maxLen = INT_MIN;
        int currMaxLen = INT_MIN;
        for(int i=0; i<n; i++){
            int len1 = expandFromCentre(s, i, i);
            int len2 = expandFromCentre(s, i, i+1);
            currMaxLen = max(len1, len2);
            if(currMaxLen > maxLen){
                maxLen = currMaxLen;
                //its somewhat like a formula
                start = i - (currMaxLen -1)/2;
            }
        }
        return s.substr(start, maxLen);
    }
};