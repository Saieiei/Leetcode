class Solution {
public:
    int findTheLongestSubstring(string s) {
        // Mapping vowels to their respective bit positions
        unordered_map<char, int> vowel_to_bit = {
            {'a', 0},
            {'e', 1},
            {'i', 2},
            {'o', 3},
            {'u', 4}
        };
        
        // Dictionary to store the first occurrence of each mask
        unordered_map<int, int> mask_dict;
        mask_dict[0] = -1; // Initialize with mask 0 at index -1
        
        int mask = 0;
        int max_len = 0;
        
        for(int index = 0; index < s.size(); ++index){
            char char_current = tolower(s[index]); // Ensure case-insensitivity
            // If the character is a vowel, toggle its corresponding bit
            if(vowel_to_bit.find(char_current) != vowel_to_bit.end()){
                int bit = vowel_to_bit[char_current];
                mask ^= (1 << bit);
            }
            
            // If this mask has been seen before, update max_len
            if(mask_dict.find(mask) != mask_dict.end()){
                int current_len = index - mask_dict[mask];
                if(current_len > max_len){
                    max_len = current_len;
                }
            }
            else{
                // Store the first occurrence of this mask
                mask_dict[mask] = index;
            }
        }
        
        return max_len;
    }
};