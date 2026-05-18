//formula based
//1st transpose, 2nd reverse 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //1st tranpose
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                //row becomes column
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};