class Solution {
public:
    bool isCircularSentence(string sentence) {
        //this is easy only
        //we just have to use stringstream ss()

        stringstream ss(sentence);
        string word;
        vector<string> words;

        while(ss>>word)
        {
            words.push_back(word);
        }

        int flag = 1;
        for(int i=0; i<words.size(); i++) //if total 5 sentences r there then, last will be index 4
        {
            if(i!=words.size()-1) //not the last word of the sentence
            {
                string s1 = words[i];
                string s2 = words[i+1];
                if(s1[s1.length()-1] != s2[0])
                {
                    flag = 0;
                    break;
                }
            }
            else //if last word
            {
                string s1 = words[i];
                string s2 = words[0];
                if(s1[s1.length()-1] != s2[0])
                {
                    flag = 0;
                    break;
                }
            }
        }
        return flag;
    }
};