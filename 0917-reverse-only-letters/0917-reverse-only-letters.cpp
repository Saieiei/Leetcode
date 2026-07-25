class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = static_cast<int>(s.length());
        //simply 2 pointers
        int leftPointer = 0;
        int rightPointer = n-1;
        //we have to keep swapping until they r at the same index;
        while(leftPointer < rightPointer){
            //we have to keep moving front if its not a alpha
            while(leftPointer<n && (!isalpha(s[leftPointer]))){
                leftPointer++;
            }
             //we have to keep moving back if its not a alpha
            while(rightPointer>0 && (!isalpha(s[rightPointer]))){
                rightPointer--;
            }
            //its time to swap now
            if(leftPointer < rightPointer){
                char temp = s[leftPointer];
                s[leftPointer] = s[rightPointer];
                s[rightPointer] = temp;
                //update the indexes
                leftPointer++;
                rightPointer--;
            }
        }
        return s;
    }
};