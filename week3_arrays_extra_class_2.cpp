#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int s = nums.size();
        vector<int> ans(s);

        for (int index = 0; index < s; ++index) {
            // Calculate the new index using the rotation formula
            int newIndex = (index + k) % s;

            // Assign the value at the current index to the new index in the rotated array
            ans[newIndex] = nums[index];
        }

        // Update the original array with the rotated elements
        nums = ans;
    }
};

// Separate function to print the elements of a vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    cout << "Original array: ";
    printVector(nums);

    solution.rotate(nums, k);

    cout << "Rotated array (right by " << k << " positions): ";
    printVector(nums);

    return 0;
}
