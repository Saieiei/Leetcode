class Solution {
public:
    bool halvesAreAlike(string s) {
        
        //lets iterate through the string and find out the no of vowels and nonvowels
        // Let's iterate through the string and find out the number of vowels and consonants in each half
        string vowels = "aeiouAEIOU";
        int noVowelsFirstHalf = 0;
        int noVowelsSecondHalf = 0;

        // Calculate the number of vowels in the first half
        for (int i = 0; i < s.length() / 2; ++i) {
            if (vowels.find(s[i]) != string::npos) {
                noVowelsFirstHalf++;
            }
        }

        // Calculate the number of vowels in the second half
        for (int i = s.length() / 2; i < s.length(); ++i) {
            if (vowels.find(s[i]) != string::npos) {
                noVowelsSecondHalf++;
            }
        }

        // Check if the number of vowels in the first half is equal to the number of vowels in the second half
        return noVowelsFirstHalf == noVowelsSecondHalf;
    }
};