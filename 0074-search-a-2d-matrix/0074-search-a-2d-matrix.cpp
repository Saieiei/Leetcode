class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        //MN
        vector<int> flatMatrix(m*n);

        //populate flatMatrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                flatMatrix[i*n +j] = matrix[i][j];  
            }
        }

        //now travese and find out
        for(int i=0; i<m*n; i++){
            if(flatMatrix[i] == target){
                return true;
            }
        }
        return false;
    }
};