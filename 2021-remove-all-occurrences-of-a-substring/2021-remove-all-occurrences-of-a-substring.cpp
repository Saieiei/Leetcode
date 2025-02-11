class Solution {
public:
 /*
   We want to remove all occurrences of 'part' from string 's'.
   Instead of repeatedly searching for "part" across the entire string,
   we can simulate this removal with a stack-like approach:

   1. Traverse each character of s.
   2. Append the character to an output string (think of it as pushing to a stack).
   3. After each append, check if the output string's tail matches 'part'.
      - If it does, remove the occurrence of 'part' from the end
        (like popping from the stack).

   This works because every time we insert a new character, the only
   new possible occurrence of 'part' could be at the end of the new string.
*/
string removeOccurrences(string s, string part) {
    // This will act as our "stack" or output builder
    string result;
    
    // Pre-calculate the length of 'part' for convenience
    int partLen = part.size();
    
    // Iterate through every character in s
    for (char c : s) {
        // "Push" the current character to our result
        result.push_back(c);

        // Check if the current tail of 'result' matches 'part'
        if (result.size() >= partLen) {
            // Compare the substring at the end of 'result' with 'part'
            if (result.compare(result.size() - partLen, partLen, part) == 0) {
                // If they match, remove this occurrence
                // (like popping from stack)
                result.erase(result.size() - partLen, partLen);
            }
        }
    }

    return result;
}
};