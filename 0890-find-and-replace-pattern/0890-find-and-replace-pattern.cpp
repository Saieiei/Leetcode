//mapping function
//week5 cl3
//we will map the pattern and each string on vector words
    //then we will compare the outputs of the mapped pattern and  each string on vector words
    //if same push back the words in a vector called ans and return it in the end
class Solution {
public:
    //mapping the strings and implementation
    void mappingTheString(string& str) //make sure to give &, or else it wont work
    {
        char start='a';
        char mapping[200]={0};
        for(auto ch:str)
        {
            if(mapping[ch]==0) //not mapping[ch]=='0'
            {
                mapping[ch]=start;
                start++;
            }
        }

        //implementation of the mapping on the string, this will affect the string which will be trasformed according to the mapping condition

        //for(auto ch:str) //this is not corect
        //{
            //str[ch]=mapping[ch];  Here, ch is a character from the string str, but you are using it as an index to access elements in the string, which is incorrect.
       // }

       for(int i=0;i<str.length();i++)
       {
           char ch=str[i];
           str[i]=mapping[ch];
       }
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        mappingTheString(pattern);

        for(string str:words) //for every string in the vector words
        {
            string temp=str; //we should not affect the str as we need the orginal string to be displayed
            mappingTheString(temp);
            if(temp==pattern)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};