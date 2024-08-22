class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        int mask = n;
        mask = mask | mask >> 1;
        mask = mask | mask >> 2;
        mask = mask | mask >> 4;
        mask = mask | mask >> 8;
        mask = mask | mask >> 16;
        
        return n ^ mask;
    }
};