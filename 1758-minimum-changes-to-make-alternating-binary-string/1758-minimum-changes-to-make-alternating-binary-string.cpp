class Solution {
public:
    int minOperations(string s) {
        string s1, s2;
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            if(i%2==0)
            {
                s1+='0';
                s2+='1';
            }
            else
            {
                s1+='1';
                s2+='0';
            }
        }
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        int count1=0, count2=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]!=s1[i])
            {
                count1++;
            }
            if(s[i]!=s2[i])
            {
                count2++;
            }
        }
        int mini=min(count1, count2);
        return mini;
    }
};