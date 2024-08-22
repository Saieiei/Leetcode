class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        //int mask = n;
        //int z  = mask >> 1; cout<<z;
        //mask = mask | mask >> 1;
        //
        //mask = mask | mask >> 2;
        //mask = mask | mask >> 4;
        //mask = mask | mask >> 8;
        //mask = mask | mask >> 16;
        //
        //return n ^ mask;
        // Create a mask with all bits set to 1 for a 32-bit integer
        int mask = 0xFFFFFFFF;

        // Determine the number of bits in the binary representation of n
        int numBits = 0;
        int temp = n;
        while (temp > 0) {
            numBits++;
            temp >>= 1;
        }

        // Create a mask with 1s only in the bit positions occupied by n
        mask = (1 << numBits) - 1;

        // XOR n with the mask to get the complement
        return n ^ mask;
    }
};