class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int sum = 0;
        vector<int> rows(mat.size());
        vector<int> columns(mat[0].size());

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    rows[i]++;
                    columns[j]++;
                }
            }
        }

        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    if (rows[i] == 1 && columns[j] == 1) {
                        sum++;
                    }
                }
            }
        }

        return sum;

    }
};