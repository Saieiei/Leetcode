#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Your exact 4 pointers
        int rowStart = 0;
        int rowEnd = m - 1;
        int colStart = 0;
        int colEnd = n - 1;
        
        // Loop until boundaries cross
        while (rowStart <= rowEnd && colStart <= colEnd) {
            
            // 1. Move Right
            for (int j = colStart; j <= colEnd; j++) {
                result.push_back(matrix[rowStart][j]);
            }
            rowStart++; // Shrink top boundary
            
            // 2. Move Down
            for (int i = rowStart; i <= rowEnd; i++) {
                result.push_back(matrix[i][colEnd]);
            }
            colEnd--; // Shrink right boundary
            
            // 3. Move Left (Check if we still have a valid row)
            if (rowStart <= rowEnd) {
                for (int j = colEnd; j >= colStart; j--) {
                    result.push_back(matrix[rowEnd][j]);
                }
                rowEnd--; // Shrink bottom boundary
            }
            
            // 4. Move Up (Check if we still have a valid column)
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    result.push_back(matrix[i][colStart]);
                }
                colStart++; // Shrink left boundary
            }
        }
        
        return result;
    }
};