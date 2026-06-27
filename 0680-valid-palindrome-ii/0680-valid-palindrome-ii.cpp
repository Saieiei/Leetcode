class Solution {
public:
    bool isPalindrome(string s, int left, int right){
        while(left<right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        //more of a formula/BH
        //N
        //2 pointers
        int left = 0;
        int right = s.size()-1;
        //start the process
        while(left<right){
            if(s[left] != s[right]){
                //it should be palindrime if they r symetric
                //we have to check from both the sides
                if(isPalindrome(s, left+1, right) || isPalindrome(s, left, right-1)){
                    return true;
                }
                else{
                    return false;
                }
            }
            left++;
            right--;
        }
        return true;
    }
};