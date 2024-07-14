class Solution {
public:
//week12
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        int cur = 0; // Current number of active spreaders
        int ans = 0; // Total number of people who know the secret
        queue<pair<int, int>> delayQ, forgetQ; // Queues for delay and forget times
        
        // Initially, one person knows the secret
        delayQ.push({1, 1});
        forgetQ.push({1, 1});
        ans = 1; // On day 1, one person knows the secret

        for (int i = 2; i <= n; i++) {
            // Step 1: Remove people who forget the secret on day i
            while (!forgetQ.empty() && forgetQ.front().first + forget == i) {
                auto front = forgetQ.front();
                forgetQ.pop();
                int no = front.second;
                ans = (ans - no + MOD) % MOD;
                cur = (cur - no + MOD) % MOD;
            }

            // Step 2: Activate new spreaders from delayQ on day i
            while (!delayQ.empty() && delayQ.front().first + delay == i) {
                auto front = delayQ.front();
                delayQ.pop();
                cur = (cur + front.second) % MOD;
            }

            // Step 3: Spread the secret
            if (cur > 0) {
                ans = (ans + cur) % MOD;
                delayQ.push({i, cur});
                forgetQ.push({i, cur});
            }
        }
        
        return ans;
    }
};