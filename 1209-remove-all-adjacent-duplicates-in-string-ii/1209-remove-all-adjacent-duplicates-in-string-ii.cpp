class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        //2 pointers, in place but we will use a extra space
        //N, N
        int slow = 0;
        int fast = 0;
        vector<int> freq(n, 0);
        //traverse through the string
        for(fast = 0; fast<n; fast++, slow++){
            //make the fast char to slow char
            s[slow] = s[fast];
            //check if we have to updat ethe freq
            if(slow > 0 && s[slow] == s[slow -1]){
                freq[slow] = freq[slow - 1] + 1;
                //if the freq is meant we have to decrease slow
                if(freq[slow] == k){
                    slow = slow - k;
                }
            }
            else{
                //new streak
                freq[slow] = 1;
            }
        }
        return s.substr(0, slow);
    }
};