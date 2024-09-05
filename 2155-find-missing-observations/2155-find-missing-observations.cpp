class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int> ans;

        // Find the sum of the already known rolls
        int sum = 0;
        for (int num : rolls) {
            sum += num;
        }

        // Calculate the total sum we need to achieve with the missing rolls
        int totalSum = mean * (rolls.size() + n);  // Total expected sum from all rolls
        int missingSum = totalSum - sum;           // Sum we need to achieve with the missing rolls

        // Check if it is possible to split the missingSum into 'n' valid dice rolls
        if (missingSum < n || missingSum > 6 * n) {
            // If missingSum is too small (< n) or too large (> 6 * n), it's impossible
            return {};
        }

        // Distribute the sum as evenly as possible
        int avg = missingSum / n;   // Average value for each missing roll
        int rem = missingSum % n;   // Remainder to distribute among the rolls

        // Resize the vector to hold the 'n' missing rolls
        ans.resize(n, avg);  // Initialize all elements to the average value

        // Distribute the remainder by adding 1 to the first 'rem' elements
        for (int i = 0; i < rem; i++) {
            ans[i]++;
        }

        return ans;
    }
};