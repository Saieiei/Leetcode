class Solution {
public:
//https://www.youtube.com/watch?v=tF9VhkSDaSI
    string nearestPalindromic(string n) {
        //this is simple brute force only
        //u just have to know various cases there can be
        //there will be 3 cases

        long long num = stoll(n);
        int len = n.length();
        if (num <= 10) return to_string(num - 1);  // Handle single-digit cases
        if (num == 11) return "9";  // Special case for 11
        
        vector<long long> candidates;
        
        // Case 1: 10^(len-1) - 1
        candidates.push_back(pow(10, len - 1) - 1);
        
        // Case 2: 10^len + 1
        candidates.push_back(pow(10, len) + 1);
        
        // Case 3: The closest palindrome by changing the middle part
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        vector<long long> prefixList = {prefix - 1, prefix, prefix + 1};
        
        for (long long p : prefixList) {
            string ps = to_string(p);
            string palindrome = ps;
            if (len % 2 != 0) ps.pop_back();
            reverse(ps.begin(), ps.end());
            palindrome += ps;
            candidates.push_back(stoll(palindrome));
        }
        
        long long closest = LLONG_MAX;
        long long minDiff = LLONG_MAX;
        
        for (long long candidate : candidates) {
            if (candidate != num) {
                long long diff = abs(candidate - num);
                if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                    closest = candidate;
                    minDiff = diff;
                }
            }
        }
        
        return to_string(closest);
    }
};