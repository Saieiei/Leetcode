class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        //vector<string> words={"ac","aabc","bc"};
        int len=words.size();
        int freqTable[256]={0}; //use array to innitialize all th evalues of  frequency table with 0 and not vector
        for(int i=0;i<len;i++) //each string
        {
            string s=words[i];
            for(int j=0;j<s.length();j++) //each character
            {
                char ch=s[j];
                freqTable[ch]++; //increment the frequency of the character
            }
        }
        int flag=0;
        for(int i=0;i<256;i++)
        {
            if(freqTable[i]%len!=0)
            {
                return false;
                //flag=1;
                //return 0;
            }
        }
        return true;
        //if(flag==0)
        //{
        //    cout<<"true";
        //}
    }
};