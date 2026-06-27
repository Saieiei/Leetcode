class Solution {
public:
    bool isPalindrome(string s) {
        //2 pointers
        //N
        int left = 0;
        int right = s.size()-1;
        //check if both r same
        while(left < right){
            //1st keep clearing anythign thats not apha
            while(left < right && !isalnum(s[left])){
                left++;
            }
            while(left < right && !isalnum(s[right])){
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            //move them forward
            left++;
            right--;
        }
        return true;
    }
};