class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // Step 1: Calculate the total sum of chalk
        long long int totalSum = 0;
        for(int i = 0; i < chalk.size(); i++) {
            totalSum += chalk[i];
        }

        // Step 2: Use modulo to reduce the problem size
        int rem = k % totalSum;

        // Step 3: Determine which student will need to replace the chalk
        for(int i = 0; i < chalk.size(); i++) {
            if(chalk[i] > rem) return i;
            rem -= chalk[i];
        }

        // Just a fallback return, this case won't really happen given the problem constraints
        return -1;
    }
};
