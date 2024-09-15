class Solution {
public:
//the intiution is impossibleeeeee
    int findTheLongestSubstring(string s) {
    unordered_map<int, int> maskMap;
    int mask = 0;
    maskMap[0] = -1;  // base case for the scenario when the entire string has even vowel count
    int maxLength = 0;
    
    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];
        
        // Update mask for vowels
        if (c == 'a') 
        {mask ^= 1 << 0;
        cout<<"mask a: "<<mask<<endl;}
        else if (c == 'e') {mask ^= 1 << 1;
        cout<<"mask e: "<<mask<<endl;}
        else if (c == 'i') {mask ^= 1 << 2;
        cout<<"mask i: "<<mask<<endl;}
        else if (c == 'o') {mask ^= 1 << 3;
        cout<<"mask o: "<<mask<<endl;}
        else if (c == 'u') {mask ^= 1 << 4;
        cout<<"mask u: "<<mask<<endl;}
        
        // Check if this mask has been seen before
        if (maskMap.find(mask) != maskMap.end()) {
            // If found, update the maxLength by calculating the difference in indices
            maxLength = max(maxLength, i - maskMap[mask]);
        } else {
            // If not found, store the first occurrence of this mask
            maskMap[mask] = i;
        }
    }
    
    return maxLength;
}
};