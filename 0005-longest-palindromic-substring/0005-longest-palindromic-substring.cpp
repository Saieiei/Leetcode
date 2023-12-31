//week5_ass_7
class Solution {
public:
    bool palindromeChecker(string& s, int start, int end)
    {
        while(start<=end) //should be <=, consider if the string is only 1 character and check eg:"a"
        {
            if(s[start]!=s[end])
            {
                return false;
                // dont put start++; end--; inside, inf loop
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        //we will use 2 pointer approach and not dp
        //we will try to find each possible substrng and check if its palindrom or nor
            //if its palindrome we will check if it > than the lasrgest palindromic string, if so assign it to the ans
        
       // int p1=0; ->i
       // int p2=0; ->j
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                //ans="";
                if(palindromeChecker(s, i, j))
                {
                    string palinstring=s.substr(i, (j-i)+1); //str.substr(starting index, length required);
                    ans=(palinstring.size()>ans.size())?palinstring:ans;
                }
            }
        }
        return ans;
        
    }
};