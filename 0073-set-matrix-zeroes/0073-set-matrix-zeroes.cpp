class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //brute force method, N^2
        //this is like ur setting up lazers on the wall
        //where u get the value as 0
        //1st traverse through it
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = true;
                    cols[j] = true;
                }
            }
        }

        //now while traversing again
        //check if its row or col was marked
        //if so change that cell to 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rows[i] || cols[j]){
                    matrix[i][j] = 0;
                }
            }
        }
        return;
    }
};