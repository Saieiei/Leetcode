class Solution {
public:
    bool closeStrings(string word1, string word2) {
        //we dont have solve with bruteforce approach 
        //u can solve this by by seeing if the frequency of the characters in word1 r same as the frequency of charaacters in word2 (its ok if the freq of the specific char is not same) (property2)
        //we have to make sure if the chars r same and no new char is present in 1 string and missing in another (both prop1 and pro2 cant distroy a char hence it will alsoways be there in the string irrespective of the operations u do )

        //1st we will find the freq of chars
        //we also lable 1 if that char is present or not 
        vector<int>s1(26,0), s2(26,0), s11(26,0), s22(26,0);
        for(char ch:word1)
        {
            s1[ch-'a']++;
            s11[ch-'a']=1;
        }
        for(char ch:word2)
        {
            s2[ch-'a']++;
            s22[ch-'a']=1;
        }
        //we have to sort the frequences so that we can compare easily 
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        return s1==s2 && s11==s22;
    }
};