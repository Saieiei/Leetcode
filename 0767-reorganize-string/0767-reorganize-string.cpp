class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        //even odd method
        //N
        //take teh char with the largest freq
        //place it all in the even index
        //fill th erest with other chars
        //if it excees the s size, then fill up the odd indexes
        //the matimatical catch: for a string of len 5, max freq should be 3
        //X freq > n+1/2
        //populate the freq
        vector<int> freq(26, 0);
        int maxFreq = 0;
        int maxFreqChar = 0;
        //traverse through the string
        for(char ch: s){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > maxFreq){
                maxFreq = freq[ch - 'a'];
                maxFreqChar = ch - 'a';
            }
        }
        //bc, check if it satisfies mathematical prop
        if(maxFreq > (n+1)/2){
            //not possible
            return "";
        }
        //now take the max char freq and put it all in the even index
        int index = 0;
        while(freq[maxFreqChar]>0){
            s[index] = maxFreqChar + 'a';
            index += 2;
            freq[maxFreqChar]--;
        }
        //it has to get over before reached the end or might have reached the end
        //fill up the remaining with the rest of the freq
        for(int i=0; i<26; i++){
            while(freq[i] > 0){
                //if it has reached the end, then continue fro index 1
                if(index >= n){
                    index = 1;
                }
                s[index] = i + 'a';
                index += 2;
                freq[i]--;
            }
        }
        return s;
    }
};