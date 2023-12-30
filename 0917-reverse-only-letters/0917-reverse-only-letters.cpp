//week5_ass_2
//we will be using 2 pointers approach
//l will be in the begining and h will be in the end
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len=s.size();
        int l=0;
        int h=len-1;
        while(l<h)
        {
            if(isalpha(s[l]) && isalpha(s[h]))
            {
                swap(s[l], s[h]);
                l++;
                h--;
            }
            else if(!isalpha(s[l]))
            {
                l++;
            }
            else
            {
                h--;
            }
        }
        return s;
    }
};