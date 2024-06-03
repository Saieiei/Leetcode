//we will iterate through both the strings at the same time (i->s, j->t)
//we will keep covering the s string with each characters from t string
//in the end we will reach the end of either of the string
//in that case we just have to return the remaing part of the t string 
//ie, len_t-j;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int len_s=s.length();
        int len_t=t.length();
        int i=0, j=0;
        while(i<len_s && j<len_t)
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                //incase the character of t is not there in that position s[i] then we move to the next position in s string (substring)
                i++;
            }
        }
        return len_t-j;
    }
};