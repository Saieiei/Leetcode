class Solution {
public:
    string updatePrefix(const string& prefix, const string& currentString){
        //traverse through the string until the 2 chars r not the same anymore
        //a smart move will be traversing though the string whoes length is the smallest
        //because we cannot have a prefix whose length is greater than the smallest string
        int prefixLength = static_cast<int>(prefix.size());
        int currentStringLength = static_cast<int>(currentString.size());
        int minLength = min(prefixLength, currentStringLength);
        //initially lets keep the updated prefix as the string whose length is smaller
        //u can use ternary operator if needed
        string updatedPrefix = "";
        if(prefixLength > currentStringLength){
            updatedPrefix = currentString;
        }
        else{
            updatedPrefix = prefix;
        }
        for(int i = 0; i<minLength; i++){
            if(prefix[i] != currentString[i]){
                updatedPrefix = updatedPrefix.substr(0, i);
                break;
            }
        }
        return updatedPrefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n = static_cast<int>(strs.size());
        //horizontal scalling
        //u take the 1st string and superimpose on another string
        //u get the prefix and take that prefix and super impose on the string
        //keep doing tuntil u all used upp all the strings in the strs vector
        //return the prefix

        //bc
        if(strs.empty()){
            return "";
        }

        string prefix = strs[0];
        //traverse through all the strings
        for(int i=1; i<n; i++){
            string currentString = strs[i];
            //bc
            //prefix of an empty string will be empty only
            if(currentString == ""){
                return "";
            }
            prefix = updatePrefix(prefix, currentString);
            //if ur prefix is empty after superimposing, 
            //then no point comparing with other strings
            if(prefix == ""){
                return "";
            }
        }
        return prefix;
    }
};