#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int s = nums.size();
        int index = 0;
        int left = 0;
        int right = s - 1;

        while (index <= right) {
            if (nums[index] == 0) {
                swap(nums[index], nums[left]);
                index++;
                left++;
            } else if (nums[index] == 2) {
                swap(nums[index], nums[right]);
                right--;
                // No need to do index++ here
            } else {
                index++;
            }
        }
    }
};

// Separate function to print the elements of a vector
void printVector(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Example usage
int main() {
    Solution solution;
    
    // Test case
    vector<int> nums = {2, 0, 1, 2, 1, 0};
    cout << "Original array: ";
    printVector(nums);

    solution.sortColors(nums);

    cout << "Sorted array: ";
    printVector(nums);

    return 0;
}


//https://leetcode.com/problems/sort-colors/