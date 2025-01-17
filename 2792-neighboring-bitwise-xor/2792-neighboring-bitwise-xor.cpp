class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool ans = 0;
        int len = derived.size();
        vector<int> original (len, 0);
        for(int i = 1; i<len; i++) //indexing from 0 only
        {
            original[i] = derived[i-1]^original[i-1];
        }
        //checker
        if(derived[len-1] == (original[len-1]^original[0])) return true;

        original.assign(len, 1);
        for(int i = 1; i<len; i++) //indexing from 0 only, but we do not wish to check the last index
        {
            original[i] = derived[i-1]^original[i-1];
        }
        //checker
        if(derived[len-1] == (original[len-1]^original[0])) return true;

        return false;
    }
};