class Solution {
public:
    string customSortString(string order, string s) {
        //N 
        //we will append on a new string based on the order
        //let scollect all the chars thats there in s
        vector<int> freq(26, 0);
        //update the freq
        for(char ch: s){
            freq[ch - 'a']++;
        }
        string ans = "";
        //just aa small optimization on space alloc
        ans.reserve(s.size());
        //now we will append the s based on order
        for(char ch: order){
            //check if that frq > 0
            if(freq[ch - 'a'] > 0){
                //if so append it 
                ans.append(freq[ch - 'a'], ch);
                //or
                //for(int i=0; i<freq[ch - 'a']; i++){
                    //ans += ch;
                //}
            }
            //after using all the freq of the ch, mark it to 0
            freq[ch - 'a'] = 0;
        }

        //now after we have arranged the chars of order, 
        //we have to also append the chars of s
        for(int i=0; i<26; i++){
            //check if that frq > 0
            if(freq[i] > 0){
                //if so append it 
                ans.append(freq[i], (i + 'a'));
                //or
                //for(int i=0; i<freq[ch - 'a']; i++){
                    //ans += ch;
                //}
            }
            //after using all the freq of the ch, mark it to 0
            freq[i] = 0;
        }
        return ans;
    }
};