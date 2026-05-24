class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //this 1 takes N^2 too but 0 space
        //this is again like magnets
        //if we find 0 we will setup magnets on the wall
        //we have to consider [0][0] separetly as it is a corner piece
        //and it can influence both the row and the col
        bool col0 = false;

        //traverse through the matrix and set up the magnets
        for(int i=0; i<m; i++){
            //check if the corner prience is 0
            if(matrix[i][0] == 0){
                col0 = true;
                //later on, in the last part, we will mark teh whole row as 0
            }

            //traverse through the rest of the col
            for(int j=1; j<n; j++){
                if(matrix[i][j] == 0){
                    //set up the magents on the walls
                    //col
                    matrix[0][j] = 0;
                    //row
                    matrix[i][0] = 0;
                }
            }
        }
        //now we enter phase 2 where we traverse from bottom right to top left
        //but we skip the 1st col
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=1; j--){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    //mark its as 0
                    matrix[i][j] = 0;
                }
            }
        }
        //in the end process the 1st col
        if(col0 == true){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
        return;
    }
};