class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        //this can be done using substr and prefix
        //we will take the 1st string as complete prefix it self
        //then in each of the string we will find if its there, if not, then decrease the prefix by 1 (substr())
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            //this will keep shrinking as it goes through the strings
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
};