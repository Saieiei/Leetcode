class Solution {
public:
//https://www.youtube.com/watch?v=tF9VhkSDaSI
    string nearestPalindromic(string n) {
        //this is simple brute force only
        //u just have to know various cases there can be
        //there will be 3 cases

        //caes1
        //here we will divide the number in to half
        //and we will reverse the 1st half and keep it in 2nd half
            //either the number itself, +1, -1
        // the same n cannot be accepted
        long long num = stoll(n);
        int len = n.length();
        
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