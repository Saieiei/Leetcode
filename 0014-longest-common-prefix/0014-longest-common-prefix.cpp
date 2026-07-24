class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = static_cast<int>(strs.size());
        //vertical scalling
        //we take the 1st string as the prefix
        //then take the 1st letter and compare it every other string
        //if that letter is present in all we take the next letter of the prefix
        //and compare it with every other strings at the same position of the letter
        //if 1 of them breaks either because the length of the string is short 
        //(teh whole string is the prefix, return it)
        //or the letters didint match, then return the substring based on the index so far

        //bc
        if(strs.empty()){
            return "";
        }

        //take the 1st strign as the prefix
        string prefix = strs[0];
        //now we have to go through its chars and compare it with every string, 
        //until something break
        int prefixLength = static_cast<int>(prefix.size());
        for(int prefixStringIndex = 0; prefixStringIndex < prefixLength; prefixStringIndex++){
            int prefixChar = prefix[prefixStringIndex];
            //now we have to compare it with other strings until something breaks
            for(int row = 1; row<n; row++){
                string currentString = strs[row];
                //if the currentString length is less than the prefix index
                //then the currentString is thre prefix to be returned
                int currentStringLength = static_cast<int>(currentString.size());
                if(currentStringLength < prefixStringIndex){
                    return currentString;
                }
                //if the chars dont match, then return the substring
                char currentStringChar = currentString[prefixStringIndex];
                if(currentStringChar != prefixChar){
                    return prefix.substr(0, prefixStringIndex);
                }
            }
        }
        //if nothing breaks till now, which means all the strings in the str
            //are the same strings or there is only 1 string in the vec
            return prefix;
    }
};