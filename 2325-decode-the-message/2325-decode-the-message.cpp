//learn something new
//week5 cl 3
class Solution {
public:
    string decodeMessage(string key, string message) {

        //encode
        char mapping[280]={0};
        char start='a';
        for(auto ch:key)
        {
            if(ch!=' ' && mapping[ch]==0) //make sure its &&
            {
                mapping[ch]=start;
                start++;
            }
        }

        //decoding
        string ans;
        for(auto ch:message)
        {
            if(ch==' ')
            {
                ans.push_back(' ');
            }
            else
            {
                char decodedCharacter=mapping[ch];
                ans.push_back(decodedCharacter);
            }
        }
        return ans;
        
    }
};