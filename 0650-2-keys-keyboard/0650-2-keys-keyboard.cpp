class Solution {
public:
    int minSteps(int n) {
        int steps = 0;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {  // Divide n by i as long as it's divisible
                steps += i;       // Add i to steps
                n /= i;           // Reduce n
            }
        }
        return steps;
    }
};
