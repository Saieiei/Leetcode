class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Sort the dictionary by length of words
    sort(dictionary.begin(), dictionary.end(), [](const string &a, const string &b) {
        return a.size() < b.size();
    });

    // Convert the sentence into a stream
    istringstream iss(sentence);
    string word;
    string result;
    
    // Iterate over each word in the sentence
    while (iss >> word) {
        string replacement = word; // Default replacement is the word itself
        for (const string& root : dictionary) {
            if (word.find(root) == 0) { // Check if the word starts with the root
                replacement = root; // Replace the word with the root
                break; // Stop checking once the shortest root is found
            }
        }
        if (!result.empty()) {
            result += " "; // Add space between words
        }
        result += replacement; // Add the replacement word to the result
    }

    return result;
}
};