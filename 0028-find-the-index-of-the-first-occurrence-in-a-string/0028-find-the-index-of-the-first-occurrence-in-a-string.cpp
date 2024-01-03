class Solution {
public:
    int strStr(string haystack, string needle) {
        //we will solve this using slidng window
        //we will iterate through each letters in haystack string (m-n) "i"
            //m is the size of the haystack and n is the size of needle
            //we have to do m-n cuz there is no point checking after 
            //for each i we will also check if its matching needle using innner loop "j"
                //if its not matching then we willl break the loop
                //but if has travelled all the wway in the inside loop"j" then we will print 0
        int m=haystack.size();
        int n=needle.size();

        for(int i=0;i<=m-n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(haystack[i+j]!=needle[j]) 
                {
                    break;
                }
                if(j==n-1)
                {
                    return i;
                }
            }
        }
        return -1;

    }
};