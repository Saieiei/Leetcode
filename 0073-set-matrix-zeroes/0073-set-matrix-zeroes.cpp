class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //brute force method, N^2
        //traverse through the matrix and find out which
        //coordinates have the value 0
        vector<vector<bool>> is0(m, vector<bool>(n, false));
        //travese through the matrix
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check if the coordinates leads to 0
                if(matrix[i][j] == 0){
                    //mark it as true
                    is0[i][j] = true;
                }
            }
        }
        //now we have all the coordinates whos value is 0
        //now travese through the matrix and update its rows and cols to 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //check if this coordinates point to 0
                if(is0[i][j] == true){
                    //make the whole row and col to 0
                    //row
                    for(int k=0; k<n; k++){
                        matrix[i][k] = 0;
                    }
                    //col
                    for(int k=0; k<m; k++){
                        matrix[k][j] = 0;
                    }

                }
            }
        }
        return;
    }
};