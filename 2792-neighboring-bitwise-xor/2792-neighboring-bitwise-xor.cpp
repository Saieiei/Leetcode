class Solution {
public:
////easy only
////we will use thge proprty of xor
////if a+b = c, then a+c = b and b+c = a
    bool doesValidArrayExist(vector<int>& derived) {
//        bool ans = 0;
//        int len = derived.size();
//        vector<int> original (len, 0);
//        for(int i = 1; i<len; i++) //indexing from 0 only
//        {
//            original[i] = derived[i-1]^original[i-1];
//        }
//        //checker
//        if(derived[len-1] == (original[len-1]^original[0])) return true;
//
//        original.assign(len, 1);
//        for(int i = 1; i<len; i++) //indexing from 0 only, 
//        {
//            original[i] = derived[i-1]^original[i-1];
//        }
//        //checker
//        if(derived[len-1] == (original[len-1]^original[0])) return true;
//
//        return false;

//Understand that from the original element, we are using each element twice to construct the derived array
//The xor-sum of the derived array should be 0 since there is always a duplicate occurrence of each element.

        int ans = 0;
        for(int element: derived)
        {
            ans = ans^element;
        }
        if(ans == 0) return 1; else return 0;
    }
};