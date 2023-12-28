//this is ratta type and very imp
//w5 cl2
class Solution {
public:

    int expand(string s, int i, int j)
    {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) // check this 1st (i >= 0 && j < s.length())
        {
            i--;
            j++;
            count++;
        }
        return count;
    }


    int countSubstrings(string s) {
        //we will use 2 pointers only
        //but these pointers will not be at the begining and another at end
        //we will have 2 sections
        //for odd section the pointers will point on each charcter and then expand, starting from s.[0] to last char in s
        //for even section he pointers p1 and p2 will be at the beginging and begining+1 and expand for each character
        //it has to pass through both the sections for each charcter
        //expand means p1 will go back, p2 will go front

        int len=s.length();
        int totalCount=0,p1=0, p2=0;
        for(int i=0;i<len;i++)
        {
            //odd section
            int oddCount=expand(s, i, i);

            //even section
            int evenCount=expand(s, i, i+1);

            totalCount=totalCount+oddCount+evenCount;
        }
        return totalCount;
    }
};