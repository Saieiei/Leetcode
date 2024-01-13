class Solution {
public:
    int minSteps(string s, string t) {
        // Check if the lengths of both strings are the same
        if (s.length() != t.length()) {
            return -1; // Invalid input, strings should be of the same length
        }

        // Count the frequency of characters in both strings
        unordered_map<char, int> sFreq, tFreq;
        for (char c : s) {
            sFreq[c]++;
        }
        for (char c : t) {
            tFreq[c]++;
        }

        // Loop over characters and calculate the minimum steps
        int steps = 0;
        for (auto& entry : sFreq) {
            char c = entry.first;
            int sCount = entry.second;
            int tCount = tFreq[c];

            if (tCount < sCount) {
                steps += sCount - tCount;
            }
        }

        return steps;
    }
};