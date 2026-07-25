class Solution {
public:
    string reverseVowels(string s) {
        int n = static_cast<int>(s.length());
        //we can do this with simply 2 pointers
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int leftPointer = 0;
        int rightPointer = n-1;
        //we have to keep on swapping until they become the same index
        while(leftPointer<rightPointer){
            //keep on moving left until we get a proper vowel
            while(leftPointer<n && (vowels.find(s[leftPointer]) == vowels.end())){
                leftPointer++;
            }
            //keep on moving right until we get a proper vowel
            while(rightPointer>0 && (vowels.find(s[rightPointer]) == vowels.end())){
                rightPointer--;
            }
            //its time to swap
            if(leftPointer<rightPointer){
                char temp = s[rightPointer];
                s[rightPointer] = s[leftPointer];
                s[leftPointer] = temp;
                leftPointer++;
                rightPointer--;
            }
        }
        return s;
    }
};