//class Solution {
//public:
//
////TLE  697 / 718 testcases passed
//    // Helper function to find the common prefix length between two strings
//    int commonPrefixLength(const string& str1, const string& str2) {
//        int len = min(str1.length(), str2.length());
//        int commonLen = 0;
//        
//        // Compare digit by digit
//        for (int i = 0; i < len; ++i) {
//            if (str1[i] == str2[i]) {
//                commonLen++;  // Increment common length if digits match
//            } else {
//                break;  // Stop when digits don't match
//            }
//        }
//        return commonLen;  // Return the length of the common prefix
//    }
//
//    // Main function to find the longest common prefix length between all pairs
//    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
//        int maxLength = 0;  // Variable to store the maximum common prefix length
//        
//        // Iterate over each pair of numbers from arr1 and arr2
//        for (int x : arr1) {
//            for (int y : arr2) {
//                // Convert integers to strings to compare their prefixes
//                string str1 = to_string(x);
//                string str2 = to_string(y);
//                
//                // Find the common prefix length between the two strings
//                int currentPrefixLength = commonPrefixLength(str1, str2);
//                
//                // Update the maximum common prefix length encountered
//                maxLength = max(maxLength, currentPrefixLength);
//            }
//        }
//        
//        return maxLength;  // Return the maximum length of the common prefix
//    }
//};
//
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> prefix;
        // store all prefix of anyone array
        for(auto& val:arr1){
            int num = val;
            while(num>0){
                prefix[num]++; // 1000 -> 1000/10 = 100 -> 100/10 = 10 -> 10/10 = 1
                num /= 10;
            }
        }

        // max length variable mx
        int mx = INT_MIN;

        // instead of creating other map we can check prefix at moment
        for(auto& val:arr2){
            int num = val;
            // count no. of digits in num
            int len = log10(num)+1;

            // again generate all prefix
            while(num>0){
                // if prefix found simply break
                if(prefix.find(num)!=prefix.end()){
                    break;
                }
                num /= 10;
                // decrease digit as we decreased prefix
                len--;
            }

            mx = max(mx, len);
        }

        return mx;
    }
};