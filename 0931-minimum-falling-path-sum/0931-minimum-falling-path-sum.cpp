
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        int ans = INT_MAX;

        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));

        for (auto& row : dp) {
            fill(row.begin(), row.end(), INT_MAX);
        }

        for (int i = 0; i < c; i++) {
            ans = min(ans, rec(0, i, matrix, dp));
        }

        return ans;
    }

private:
    int rec(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp) {
        if (i == arr.size()) return 0;
        if (j < 0 || j >= arr[0].size()) return INT_MAX;

        if (dp[i][j] != INT_MAX) return dp[i][j];

        int ops1 = rec(i + 1, j - 1, arr, dp);
        int ops2 = rec(i + 1, j, arr, dp);
        int ops3 = rec(i + 1, j + 1, arr, dp);

        dp[i][j] = arr[i][j] + min(ops1, min(ops2, ops3));
        return dp[i][j];
    }
};