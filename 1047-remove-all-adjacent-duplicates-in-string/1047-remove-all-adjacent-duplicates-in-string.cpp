class Solution {
public:
    string removeDuplicates(string s) {
        //we will solve this by creating a new string method
        string s2="";
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            char ch=s[i];
            if(s2.empty())
            {
                s2.push_back(ch);
                continue;
            }
            if(s2.back()!=ch)
            {
                s2.push_back(ch);
            }
            else
            {
                s2.pop_back();
            }
        }
        return s2;
    }
   
};