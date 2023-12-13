#include <vector>

class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        int n = nums.size();
        std::vector<int> lsum(n, 0);
        std::vector<int> rsum(n, 0);

        lsum[0] = 0;
        rsum[n - 1] = 0;
        int flag = 0;

        for (int i = 1; i < n; i++) {
            lsum[i] = lsum[i - 1] + nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            rsum[i] = rsum[i + 1] + nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            if (lsum[i] == rsum[i]) {
                return i;
            }
        }
        return -1;
    }
};
