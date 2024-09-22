class Solution {
public:
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;  // Map to store the index of each character
    int maxLength = 0;                      // Variable to keep track of the maximum length
    int start = 0;                          // The starting index of the current window (substring)

    // Traverse through each character in the string
    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // If the character has already been encountered and is inside the current window,
        // move the start of the window to the right of the previous occurrence.
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            start = charIndexMap[currentChar] + 1;
        }

        // Update the character's latest index
        charIndexMap[currentChar] = end;

        // Calculate the current window size and update maxLength if it's larger than the previous maxLength
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

};