class Solution {
public:
    string makeFancyString(string s) {
        int freq = 0;
        int k = 0;
        int i = 0;
        int j = 1;
        while(i<s.size())
        {
            freq = 0;
            bool same = true;
            while(same)
            {
                if(s[i] == s[j]) 
                {
                    freq++;
                    j++;
                }
                else break;
            }
            if(freq>=2)
            {
                s[k] = s[i];
                k++;
                s[k] = s[i];
                k++;
            }
            else
            {
                if(freq == 0) 
                {
                    s[k] = s[i];
                    k++;
                }
                if(freq == 1)
                {
                    s[k] = s[i];
                    k++;
                    s[k] = s[i];
                    k++;
                }
            }
            i = j;
            j++;
        }
        s = s.substr(0, k);
        return s;
    }
};