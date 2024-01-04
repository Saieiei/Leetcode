class Solution {
public:
    int strStr(string haystack, string needle) {
        //we can also use substring function
        int m=haystack.size();
        int n=needle.size();

        for(int i=0;i<=m-n;i++)
        {
            if(haystack.substr(i, n)==needle)
            {
                return i;
            }
        }
        return -1;

    }
};