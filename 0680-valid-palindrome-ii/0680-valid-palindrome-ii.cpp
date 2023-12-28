class Solution {
public:

    bool palindromeChecker(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }


    bool validPalindrome(string s) {
        //we will use 2 pointers
        //1st pointer at the begining
        //2nd pointer in the end
        //keep check if same
        //if not same 
            //u have the seachspace from the 1st pointer till the last pointer
            //for 1st pointer delete the 1st character and check if palindrome
            //for last pointer delete the last charcter and check if palindme
            //if any1 is possible return true
        int i=0, j=s.length()-1;
        bool possible1,  possible2;
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                possible1=palindromeChecker(s, i+1, j);
                possible2=palindromeChecker(s, i, j-1);
                return possible1 || possible2;
            }
        }
        return true;
        
    }
};