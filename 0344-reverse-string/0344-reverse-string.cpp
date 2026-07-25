class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = static_cast<int>(s.size());
        //2 pointers
        int leftPointer = 0;
        int rightPointer = n - 1;
        //keep swapping until they come on the same index
        while(leftPointer<rightPointer){
            char temp = s[leftPointer];
            s[leftPointer] = s[rightPointer];
            s[rightPointer] = temp;
            leftPointer++;
            rightPointer--;
        }
    }
};