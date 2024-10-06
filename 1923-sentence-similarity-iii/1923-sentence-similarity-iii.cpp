class Solution {
public:
    // Helper function to split a sentence into words and store them in a vector
vector<string> splitSentence(const string &sentence) {
    vector<string> words;
    stringstream ss(sentence);
    string word;
    
    // Using stringstream to split the sentence by spaces
    while (ss >> word) {
        words.push_back(word);
    }
    
    return words;
}

bool areSentencesSimilar(string sentence1, string sentence2) {
    // First, split both sentences into words using the helper function
    vector<string> words1 = splitSentence(sentence1);
    vector<string> words2 = splitSentence(sentence2);
    
    // Ensure sentence1 is always the smaller one, if not swap them
    if (words1.size() > words2.size()) {
        swap(words1, words2);
    }
    
    int start = 0;
    int end = words1.size() - 1;
    int n2 = words2.size() - 1;
    
    // Matching prefix
    while (start <= end && words1[start] == words2[start]) {
        start++;
    }
    
    // Matching suffix
    while (end >= start && words1[end] == words2[n2 - (words1.size() - 1 - end)]) {
        end--;
    }
    
    // If start has crossed end, it means all unmatched words can fit inside the other sentence
    return start > end;
}
};