class Solution {
public:
    int lengthOfLastWord(string s) {
        //we will put a pointer on the back of the string
        int p=s.size()-1;
        int ans=0;
        //we will keep travelling back and skipping all spaces until we reach a char which is not a ' '
        while(p>=0 && s[p]==' ')
        {
            p--;
        }
        //now since we are on a char we need to keep travelling until we get a space and each time we move we will count the size of the word
        while(p>=0 && s[p]!=' ')
        {
            p--;
            ans++;
        }
        return ans;
        
    }
};