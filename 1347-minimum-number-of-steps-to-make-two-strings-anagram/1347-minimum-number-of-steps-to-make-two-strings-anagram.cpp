class Solution {
public:
    int minSteps(string s, string t) {
        // we will use unordered_map to to ocount the values of each character
        // in string s and t
        unordered_map<char, int> sFreq, tFreq;
        // if th elengths r not same its just not possible to mach every freq of
        // the char in string s with string t
        if (s.length() != t.length()) {
            return -1;
        }
        // now lets try to find out the freq of each char in string s and t
        for (auto c : s) {
            sFreq[c]++; // go to that index and increase the freq
            // for(auto pair:sFreq)
            //{
            //    cout<<"{"<<pair.first<<": "<<pair.second<<"}";
            //}
            // cout<<endl;
        }

        for (auto c : t) {
            tFreq[c]++; // go to that index and increase the freq
        }
        // cout<<sFreq<<endl<<tFreq<<endl; u can not print a map like this
        // unforctunatly to print a unordered_map u need to use forloop for(auto
        // pair:sFreq)
        //{
        // cout<<"{"<<pair.first<<": "<<pair.second<<"}";
        //}
        // now Loop over all characters if the frequency of a character in t is
        // less than the frequency of the same character in s then add the
        // difference between the frequencies to the answer.
        int steps=0;
        for(auto pair:sFreq)
        {
            char ch=sFreq.first;
            int sCount=sFreq.second;
            int tCount=tFreq[ch];
            if(tCount>cCount)
            {
                steps=steps+tCount-sCount;
            }
        }
        return steps;
    }
};