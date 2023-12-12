#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
        }

        // Formula to calculate the sum of the first n natural numbers AP
        int totalSum = (n * (1 + n)) / 2;
        int ans = totalSum - sum;

        return ans;
    }
};

int main() {
    Solution solution;

    // Test case
    vector<int> nums = {3, 0, 1};
    int missingNumber = solution.missingNumber(nums);

    cout << "The missing number is: " << missingNumber << endl;

    return 0;
}

//https://leetcode.com/problems/missing-number/