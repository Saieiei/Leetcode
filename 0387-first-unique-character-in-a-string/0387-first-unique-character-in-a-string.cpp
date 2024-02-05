class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> charFrequency;

        // Count the frequency of each character
        for (char c : s) {
            charFrequency[c]++;
        }

        // Find the first character with a frequency of 1
        for (int i = 0; i < s.size(); ++i) {
            if (charFrequency[s[i]] == 1) {
                return i;
            }
        }

        // If no unique character is found, return -1
        return -1;
    }
};