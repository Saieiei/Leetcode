class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        //bruteforce approach 
        //38 / 42 testcases passed
    //    int ans = 0;
    //    for(int i=0; i<nums1.size(); i++)
    //    {
    //        for(int j=0; j<nums2.size(); j++)
    //        {
    //            ans ^= nums1[i]^nums2[j];
    //        }
    //    }
    //return ans;
    
        //using mathematics rules
        // Variable to hold the XOR of all elements in nums1
        int xor1 = 0;
        // Compute XOR for all elements in nums1
        for (int a : nums1) {
            xor1 ^= a; // XOR accumulate each element
        }

        // Variable to hold the XOR of all elements in nums2
        int xor2 = 0;
        // Compute XOR for all elements in nums2
        for (int b : nums2) {
            xor2 ^= b; // XOR accumulate each element
        }

        // The final result. We add xor1 if the size of nums2 is odd,
        // and xor2 if the size of nums1 is odd.
        int result = ((nums2.size() % 2 != 0) ? xor1 : 0) ^ ((nums1.size() % 2 != 0) ? xor2 : 0);

        // Output the result
        //cout << "The XOR of all integers in nums3 is: " << result << endl;

    return result; // End of program
    }
};