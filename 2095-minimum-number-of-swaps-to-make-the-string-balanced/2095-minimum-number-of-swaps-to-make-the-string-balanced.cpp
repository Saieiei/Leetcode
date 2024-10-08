class Solution {
public:
    int minSwaps(string s) {
        //u will not get the intuation at 1st
        //see, if u have a opening bracket and then the closing bracket then no problem (open++, open--)
        //but if teh closing bracket comes 1st, then that becomes a problm, 
        //like u will be able to eliminate the pairs of bracket, the 1 which is not balanced, fill fall under unbalached
        //unbalanced is the 1, where the closing bracket comes 1st, unbalaced will always be odd, as its correspondig pair will be in the open
        //this not stack

        int open = 0;
        int unbalanced = 0;

        for(char c: s)
        {
            if(c == '[') open++;
            else
            {
                if(open>0) open--;
                else unbalanced++;
            }
        }

        return (unbalanced+1)/2;
    }
};