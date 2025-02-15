/*
  Helper function: checkPartition
  --------------------------------
  Given a string 's' which represents the decimal digits of i^2,
  and a target sum 'target' (initially i),
  we want to see if we can pick contiguous substrings from 's'
  (in order) such that the sum of these substrings equals 'target'.

  We use DFS with memoization to efficiently explore substring sums.

  Parameters:
    s       - the string representation of i^2
    idx     - current index in the string s
    target  - the remaining sum we need from the substrings
    memo    - a 2D memo table for storing intermediate results:
              memo[idx][target] can be 0, 1, or -1:
                 1 means "true", 0 means "false", -1 means "not computed"
  
  Return:
    true if we can partition the substring s[idx...] to sum to 'target',
    false otherwise.
*/
bool checkPartition(const string &s, int idx, int target, vector<vector<int>> &memo) {
    // If we've reached the end of the string:
    if (idx == (int)s.size()) {
        // If target == 0, we found a valid partition
        return (target == 0);
    }

    // If already computed, return stored result
    if (memo[idx][target] != -1) {
        return (memo[idx][target] == 1);
    }

    // Attempt to form substrings s[idx..j]
    long long val = 0;
    for (int j = idx; j < (int)s.size(); ++j) {
        // Build the number by adding the current digit
        val = val * 10 + (s[j] - '0');
        
        // If val exceeds our target, no point continuing
        if (val > target) break;

        // Otherwise, check recursively if we can partition the rest
        if (checkPartition(s, j + 1, target - val, memo)) {
            memo[idx][target] = 1;  // Store "true"
            return true;
        }
    }

    // If no partition worked, store and return false
    memo[idx][target] = 0;
    return false;
}


class Solution {
public:
    /*
      punishmentNumber
      ----------------
      Given an integer n, this function returns the punishment number of n.
      That is, the sum of i^2 for all i in [1..n] where i^2 can be split
      into contiguous substrings that sum to i.
    */
    int punishmentNumber(int n) {
        long long result = 0; // Use long long to store the sum safely

        for (int i = 1; i <= n; ++i) {
            long long squareVal = 1LL * i * i; // i^2 in 64-bit
            string s = to_string(squareVal);   // convert i^2 to string

            // Prepare memo: dimensions [length_of_s][i+1]
            // We'll store -1 initially, meaning "uncomputed"
            vector<vector<int>> memo(s.size(), vector<int>(i + 1, -1));

            // Check if we can partition s so that it sums to i
            if (checkPartition(s, 0, i, memo)) {
                result += squareVal;
            }
        }
        return (int)result;
    }
};