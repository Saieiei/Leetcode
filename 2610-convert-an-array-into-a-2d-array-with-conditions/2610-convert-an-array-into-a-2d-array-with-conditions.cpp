class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        
        vector<vector<int>> result;

    for (int num : nums) {
        bool added = false;

        for (vector<int>& row : result) {
            if (find(row.begin(), row.end(), num) == row.end()) {
                row.push_back(num);
                added = true;
                break;
            }
        }

        if (!added) {
            result.push_back({num});
        }
    }

    return result;
    }
};